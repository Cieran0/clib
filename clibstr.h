#include <iostream>

namespace clib
{

    class string
    {
    public:
        string(char *s)
        {
            size_t len = getLengthOfCharPtr(s);
            value = (char*)malloc(sizeof(char)*(len+1));
            for (size_t i = 0; i < len; i++)
            {
                value[i] = s[i];
            }
            value[len]='\0';
        }
        string() {
            value = nullptr;
        }
        string(int size) 
        {
            value = (char*)malloc(sizeof(char)*size+1);
            value[size] = '\0';
        }
        ~string() {}
        size_t size()
        {
            return getLengthOfCharPtr(value);
        }

        string remove(char c) 
        {
            size_t len = size();
            size_t index = 0;
            char buffer[(len-countOccur(c))+1];
            for (size_t i = 0; i < len; i++)
            {
                if(value[i] != c) 
                {
                    buffer[index] = value[i];
                    index++;
                } 
            }
            buffer[(len-countOccur(c))] = '\0';
            return string(buffer);
        }

        string substring(size_t index, size_t length)
        {
            if (length == 0) return string(0);
            char buffer[length+1];
            for (size_t i = 0; i < length; i++)
            {
                buffer[i] = value[index+i];
            }
            buffer[length] = '\0';
            return string(buffer);
        }

        string *split(char splitChar, size_t Ssize)
        {
            string* strs = (string*)malloc(0);
            string newS(value);
            newS.append(splitChar);
            Ssize = 0;
            int end =0;
            int start = 0;

            while (end < newS.size())
            {
                if (newS[end] == splitChar)
                {
                    if ((end - start) > 0)
                    {
                        Ssize++;
                        strs = (string*)realloc(strs, (sizeof(string)*(Ssize)));
                        strs[Ssize-1] =  newS.substring(start, (end-start));
                    }

                    start = end + 1;
                }
                end++;
            }
            return strs;
        }

        string replace(char replacee, char replacer) 
        {
            string s;
            char *buff = (char *)malloc(sizeof(char) * size());
            for (size_t i = 0; i < size(); ++i)
            {
                if (value[i] == replacee) buff[i] = replacer;
                else buff[i] = value[i];
            }
            s = buff;
            return s;
        }

        char operator[](const size_t &i)
        {
            return value[i];
        }

        bool operator==(const string &s)
        {
            if (((string)s).size() != size())
                return false;

            for (size_t i = 0; i < size(); ++i)
            {
                if (s.value[i] != value[i])
                    return false;
            }
            return true;
        }

        bool operator==(const char &c) 
        {
            if (size() != 1) return false;
            if (value[0] == c) return true;
            return false;
        }

        bool operator!=(const string &s)
        {
            return !(operator==(s));
        }

        string operator+(const string &s)
        {
            char *buff1 = value;
            char *buff2 = s.value;
            char *buff3 = (char *)malloc((sizeof(char) * (size() + ((string)s).size())));
            for (size_t i = 0; i < size(); ++i)
            {
                buff3[i] = buff1[i];
            }
            for (size_t i = 0; i < ((string)s).size(); ++i)
            {
                buff3[i + size()] = buff2[i];
            }
            string newStr = buff3;
            return newStr;
        }

        string operator+(const char *&c)
        {
            string s = (char *)c;
            return operator+(s);
        }

        string operator+(const char &c)
        {
            string s = (char *)&c;
            return operator+(s);
        }

        void operator+=(const string &s)
        {
            this->value = (operator+(s).value);
        }

        void operator+=(const char *&c)
        {
            this->value = (operator+(c).value);
        }

        void operator+=(const char &c)
        {
            this->value = (operator+(c).value);
        }

        size_t countOccur(char c) 
        {
            size_t count = 0; 
            for (size_t i = 0; i < size(); ++i)
            {
                if (value[i] == c) count++;
            }
            return count;
        }

        size_t findChar(char c)
        {
            for (size_t i = 0; i < size(); ++i)
            {
                if (value[i] == c)
                    return i;
            }
            return -1;
        }

        void append(char c)
        {
            size_t len = size()+1;
            value = (char*)realloc(value, (len+1));
            value[len-1] = c;
            value[len] = '\0';

        }

        operator char*() { return value; }

        friend std::ostream &operator<<(std::ostream &os, string a);

    private:
        char *value;



        size_t getLengthOfCharPtr(char* charPtr)
        {
            if (value == nullptr )
            {
                return 0;
            }
            
            size_t i = 0;
            while (charPtr[i] != '\0')
            {
                ++i;
            }
            return i;
        }
    };

    std::ostream &operator<<(std::ostream &os, string a)
    {
        os << a.value;
        return os;
    }

}
