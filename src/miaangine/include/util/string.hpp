#ifndef _MIA_STRING_HPP
#define _MIA_STRING_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>

namespace mia
{
    class string
    {
    private:
        char *str;
        size_t len;

    public:
        string(const char *value)
        {
            if (value == nullptr)
            {
                len = 0;
                str = (char*)calloc(1, sizeof(char));
                return;
            }

            len = strlen(value);
            str = (char*)malloc(len + 1);
            strcpy(str, value);
        }

        operator const char* () const
        {
            return str;
        }
        const char* str() const 
        {
            return str;
	    }

        bool empty()
        {
            return len == 0;
        }

        bool operator== (const string& value) 
        {
            return len == value.len && strcmp(str, value.str) == 0;
        }
        bool operator== (const char* value) 
        {
            return strcmp(str, value) == 0;
        }

        bool operator!= (const string& value) 
        {
            return len != value.len || strcmp(str, value.str) != 0;
        }
        bool operator!= (const char* value) 
        {
            return strcmp(str, value) != 0;
        }
	
        const char* operator+=(const char* value) //TODO
        {
            size_t valueLen = strlen(value);
            size_t newLen = len + valueLen;

            char* newStr = (char*)malloc(newLen);
            memcpy(newStr, str, len + 1);
            memcpy(&newStr[len], value, valueLen);
            str = newStr;
            
            str[newLen] = '\0';
            
            len = newLen;
        }
    };
}

#endif