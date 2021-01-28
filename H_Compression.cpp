//
// Created by tompa on 28.01.2021.
//

#include "H_Compression.h"
#include <map>
#include <sstream>


std::string H_Compression::compress(const std::string &text) {
    //Construct corresponding Huffman tree
    H_Tree hTree(text);

    //construct byte -> bit sequence mapping
    std::map<char, std::string> seq = hTree.get_bit_sequence_mapping();

    std::ostringstream os;
    for(const char& c : text) {
        os << seq[c];
    }

    return os.str();
}
