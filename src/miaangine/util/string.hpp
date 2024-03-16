#ifndef _MIA_STRING_HPP
#define _MIA_STRING_HPP

#include <cstring>

namespace mia
{
    class string
    {
    public:
        string(const char *content = ""):
            _content(new char[strlen(content) + 1])
        {
            strcpy(_content, content);
        }

        string(const string &str) noexcept:
            _content(str._content)
        {}

        ~string() 
        {
            delete[](_content);
        }

        inline string& operator=(const string &other) noexcept
        {
            if (this != &other)
            {
                delete[](_content);
                _content = other._content;
            }

            return *this;
        }

        string& operator=(const char *content)
        {
            delete[](_content);
            _content = new char[strlen(content) + 1];
            strcpy(_content, content);

            return *this;
        }

        inline string& operator+=(const string &other) 
        {
            size_t len = strlen(_content) + strlen(other._content);
            char *temp = new char[len + 1];
            strcpy(temp, _content);
            strcat(temp, other._content);

            delete[](_content);
            _content = temp;

            return *this;
        }

        inline string& operator+=(const char *content) 
        {
            size_t len = strlen(_content) + strlen(content);
            char *temp = new char[len + 1];
            strcpy(temp, _content);
            strcat(temp, content);

            delete[](_content);
            _content = temp;

            return *this;
        }

        inline bool operator==(const string &other)
        {
            if (_content == other._content) return true;

            int llen = strlen(_content);
            int rlen = strlen(other._content);

            if (llen != rlen) return false;

            for (int i = 0; i < llen; i++)
            {
                if (_content[i] != other._content[i])
                    return false;
            }

            return true;
        }

        inline bool operator==(const char *content)
        {
            int llen = strlen(_content);
            int rlen = strlen(content);

            if (llen != rlen) return false;

            for (int i = 0; i < llen; i++)
            {
                if (_content[i] != content[i])
                    return false;
            }

            return true;
        }

        inline bool operator!=(const string &other)
        {
            int llen = strlen(_content);
            int rlen = strlen(other._content);

            if (llen != rlen) return true;

            for (int i = 0; i < llen; i++)
            {
                if (_content[i] != other._content[i])
                    return true;
            }

            return false;
        }

        inline bool operator!=(const char *content)
        {
            int llen = strlen(_content);
            int rlen = strlen(content);

            if (llen != rlen) return true;

            for (int i = 0; i < llen; i++)
            {
                if (_content[i] != content[i])
                    return true;
            }

            return false;
        }

        inline string& copy(const string &other)
        {
            delete[](_content);
            _content = new char[strlen(other._content) + 1];
            strcpy(_content, other._content);

            return *this;
        }

    private:
        char* _content;

    public:
        const char* str() const 
        {
            return _content;
        }
    };
}

#endif