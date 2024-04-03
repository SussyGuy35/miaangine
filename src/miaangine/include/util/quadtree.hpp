#ifndef _MIA_QUADTREE_HPP
#define _MIA_QUADTREE_HPP

#include "rect.hpp"
#include <memory>
#include <array>
#include <vector>
#include <list>
#include <utility>

namespace mia
{
    template <typename T>
    class Quadtree
    {
    public:
        Quadtree(const rect &size = {{0, 0}, {1, 1}}, const size_t depth = 0):
            _depth(depth)
        {
            resize(size);
        }

    protected:
        size_t _depth = 0;
        rect _rect;
        std::array<rect, 4> _rchild{};
        std::array<std::shared_ptr<Quadtree<T>>, 4> _pchild{};
        std::vector<std::pair<T, rect>> _items;
    
    public:
        void resize(const rect &area)
        {
            clear();
            _rect = area;
            v2f childSize = _rect.size / 2;

            _rchild = {
                rect(_rect.position, childSize),
                rect({_rect.position.x + childSize.x, _rect.position.y}, childSize),
                rect({_rect.position.x, _rect.position.y - childSize.y}, childSize),
                rect({_rect.position.x + childSize.x, _rect.position.y - childSize.y}, childSize),
            };
        }

        void clear()
        {
            _items.clear();
            for (int i = 0; i < 4; i++)
            {
                if (_pchild[i]) _pchild[i]->clear();
            }
        }

        size_t size() const
        {
            size_t count = _items.size();
            for (int i = 0; i < 4; i++)
            {
                if (_pchild[i]) count += _pchild[i]->size();
            }
            return count;
        }

        void insert(const T &item, const rect &itemRect)
        {
            for (int i = 0; i < 4; i++)
            {
                if (_depth + 1 < 8 && _rchild[i].contain(itemRect)) // TODO add maxdepth
                {
                    if (!_pchild[i])
                    {
                        _pchild[i] = std::make_shared<Quadtree<T>>(_rchild[i], _depth + 1); 
                    }

                    _pchild[i]->insert(item, itemRect);
                    return;
                }
            }
            _items.push_back({item, itemRect});
        }

        std::list<T> search(const rect area) const
        {
            std::list<T> itemList;
            search(area, itemList);
            return itemList;
        }

        void search(const rect &area, std::list<T> &itemList) const
        {
            for (const auto &item : _items)
            {
                if (area.overlap(item.second))
                {
                    itemList.push_back(item.first);
                }
            }

            for (int i = 0; i < 4; i++)
            {
                if (_pchild[i])
                {
                    if (area.contain(_rchild[i]))
                    {
                        _pchild[i]->additemsto(itemList);
                    }
                    else if (area.overlap(_rchild[i]))
                    {
                        _pchild[i]->search(area, itemList);
                    }
                }
            }
        }

        void additemsto(std::list<T> &itemList)
        {
            for (const auto &item : _items)
                itemList.push_back(item.first);

            for (int i = 0; i < 4; i++)
                if (_pchild[i]) _pchild[i]->additemsto(itemList);
        }

        rect area()
        {
            return _rect;
        }
    };
}

#endif