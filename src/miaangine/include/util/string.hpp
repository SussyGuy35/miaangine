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
        char *val;
        size_t len;

    public:
        string(const char *value = "")
        {
            if (value == nullptr)
            {
                len = 0;
                val = (char*)calloc(1, sizeof(char));
                return;
            }

            len = strlen(value);
            val = (char*)malloc(len + 1);
            strcpy(val, value);
        }

        string(const string& other) 
        {
            val = (char*)malloc(other.len + 1);
            strcpy(val, other.val);
            len = other.len;
        }
        string(string&& other) noexcept
        {
            val = other.val;
            len = other.len;
            other.val = nullptr;
        }

        ~string()
        {
            delete val;
        }

        operator const char* () const
        {
            return val;
        }
        const char* str() const 
        {
            return val;
	    }
        int length() const
        {
            return len;
        }
        bool empty() const
        {
            return len == 0;
        }

        string& operator= (const string& other) 
        {
            val = (char*)malloc(other.len + 1);
            strcpy(val, other.val);
            len = other.len;
            return *this;
        }
        string& operator= (string&& other) noexcept
        {
            val = other.val;
            len = other.len;
            other.val = nullptr;
            return *this;
        }
        string& operator= (const char* value)
        {
            delete val;

            if (value == nullptr)
            {
                len = 0;
                val = (char*)calloc(1, sizeof(char));
                return *this;
            }

            len = strlen(value);
            val = (char*)malloc(len + 1);
            strcpy(val, value);
            return *this;
        }

        bool operator== (const string& value) 
        {
            return len == value.len && strcmp(val, value.val) == 0;
        }
        bool operator== (const char* value) 
        {
            return strcmp(val, value) == 0;
        }

        bool operator!= (const string& value) 
        {
            return len != value.len || strcmp(val, value.val) != 0;
        }
        bool operator!= (const char* value) 
        {
            return strcmp(val, value) != 0;
        }

        const char* operator+=(const char* value)
        {
            size_t valueLen = strlen(value);
            size_t newLen = len + valueLen;

            char* newStr = (char*)malloc(newLen);
            memcpy(newStr, val, len + 1);
            memcpy(&newStr[len], value, valueLen);
            
            delete val;

            val = newStr;
            val[newLen] = '\0';
            len = newLen;

            return val;
        }
        const char* append(const char* value)
        {
            size_t valueLen = strlen(value);
            size_t newLen = len + valueLen;

            char* newStr = (char*)malloc(newLen);
            memcpy(newStr, val, len + 1);
            memcpy(&newStr[len], value, valueLen);
            
            delete val;
            
            val = newStr;
            val[newLen] = '\0';
            len = newLen;

            return val;
        }
    };
}

#endif