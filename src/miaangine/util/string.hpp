#ifndef _MIA_STRING_HPP
#define _MIA_STRING_HPP

#include <cstring>

namespace mia
{
    class string
    {
    public:
        string():
            _content("")
        {}

        string(char *content)
        {
            delete[](_content);
            _content = content;
        }

        string(const char *content)
        {
            delete[](_content);
            _content = new char[strlen(content)];
            strcpy(_content, content);
        }

        string(string &str)
        {
            delete[](_content);
            _content = str._content;
        }

        string(const string &str)
        {
            delete[](_content);
            _content = new char[strlen(str._content)];
            strcpy(_content, str._content);
        }

        ~string() 
        {
            delete[](_content);
        }

        inline string& operator=(const string &other) 
        {
            if (this != &other) 
            {
                delete[](_content);
                _content = new char[strlen(other._content)];
                strcpy(_content, other._content);
            }

            return *this;
        }

        inline string& operator=(const char *content) 
        {
            delete[](_content);
            _content = new char[strlen(content)];
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