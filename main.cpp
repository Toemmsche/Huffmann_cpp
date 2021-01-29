#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include "H_Compression.h"

int main() {
    std::streamsize size;
    std::ifstream file;
    file.open("D:\\Programming\\Huffmann\\test.txt", std::ios::binary|std::ios::ate|std::ios::in);
    char* memblock;
    if(file.is_open()) {
       size = file.tellg();
       memblock = new char[size];
        file.seekg (0, std::ios::beg);
       file.read(memblock, size);
       file.close();
    }
   auto s = std::string(memblock);
    std::cout << s << std::endl;
    auto p = H_Compression::compress(s);
    std::string c = p.second;
    std::cout <<  H_Compression::decompress(p.first, c) << std::endl;
}
