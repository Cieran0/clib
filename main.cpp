#include <clib.h>

int main()
{
    clib::string s = (char *)"Hello, ";
    s += clib::string((char *)"World!");
    int strsSize;
    clib::string *strs = s.split(' ', &strsSize);
    std::cout << s << std::endl;
    std::cout << s.findChar('!') << std::endl;
    for (size_t i = 0; i < strsSize; ++i)
    {
        std::cout << s.split(' ')[i] << std::endl;
    }

    return 0;
}