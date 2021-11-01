#include <iostream>

namespace clib
{

    class string
    {
    public:
        string(char *s)
        {
            value = s;
        }
        string()
        {
        }
        size_t size()
        {
            int i = 0;
            while (value[i] != 0x00)
            {
                ++i;
            }
            return i;
        }

        string substring(size_t index, size_t length)
        {
            string s;
            char *buff = (char *)malloc(sizeof(char) * length);
            for (size_t i = 0; i < length; ++i)
            {
                buff[i] = value[index + i];
            }
            s = buff;
            return s;
        }

        string *split(char splitChar, int *size = NULL)
        {
            string newS = string(value) + splitChar;
            size_t start = 0;
            size_t end = 0;
            size_t count = 0;
            size_t current = 0;

            while (end < newS.size())
            {
                if (newS[end] == splitChar)
                {
                    if ((end - start) > 0)
                    {
                        count++;
                    }

                    start = end + 1;
                }
                end++;
            }

            end = start = 0;
            string *strs = (string *)malloc(sizeof(string) * count);
            while (end < newS.size())
            {
                if (newS[end] == splitChar)
                {
                    if ((end - start) > 0)
                    {
                        strs[current] = newS.substring(start, (end - start));
                        current++;
                    }

                    start = end + 1;
                }
                end++;
            }
            if (size != NULL)
            {
                *size = count;
            }

            return strs;
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

        size_t findChar(char c)
        {
            for (size_t i = 0; i < size(); ++i)
            {
                if (value[i] == c)
                    return i;
            }
            return -1;
        }

        friend std::ostream &operator<<(std::ostream &os, string a);

    private:
        char *value;
    };

    std::ostream &operator<<(std::ostream &os, string a)
    {
        os << a.value;
        return os;
    }

}
