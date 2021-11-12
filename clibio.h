#include <iostream>
#include <fstream>
namespace clib {

    #if __has_include ("clibstr.h")
        string FileReadAllText(char* name)
        {
            std::ifstream file(name);
            file.seekg(0, std::ios::end);
            size_t size = file.tellg();
            string buffer(size);
            file.seekg(0);
            file.read((char*)buffer,size);
            return buffer;
        }
    #else
        char* FileReadAllText(char* name)
        {
            std::ifstream file(name);
            file.seekg(0, std::ios::end);
            size_t size = file.tellg();
            char* buffer = (char*)malloc(size*sizeof(char));
            file.seekg(0);
            file.read(&buffer[0],size);
            return buffer;
        }
    #endif

}