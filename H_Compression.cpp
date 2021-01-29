//
// Created by tompa on 28.01.2021.
//

#include "H_Compression.h"
#include <map>
#include <sstream>
#include <vector>


std::pair<H_Tree*, std::string> H_Compression::compress(const std::string &text) {
    //Construct corresponding Huffman tree
    auto hTree = new H_Tree(text);

    //construct byte -> bit sequence mapping
    std::map<char, std::string> seq = hTree->get_bit_sequence_mapping();

    std::ostringstream os;

    //amount of filled spots for the next char
    int filled = 0;
    unsigned char next = 0;
    for (const char &c : text) {
        for (const char &bit : seq[c]) {
            //append to result??
            if (filled == 8) {
                os << next;
                //reset next character
                next = 0;
                filled = 0;
            }
            //shift left without adding
            next = next << 1;
            if (bit == '1') {
                //add one bit
                next++;
            }
            filled++;
        }
    }
    //append last char
    next = next << (8 - filled);
    os << next;

    return std::pair(hTree, os.str());
}

std::string H_Compression::decompress(const H_Tree* hTree, const std::string &compressed) {

    std::ostringstream os;

    //how many bits we have looked at for each char
    int cleared = 0;

    //traverse the compressed string
    int i = 0;
    unsigned char bit_seq = compressed[i++];

    while(true) {
        //traverse tree until leaf is reached
        H_Tree_Node* node  = hTree->root;
        while(!node->val) {
            if(cleared == 8) {
                //break out of outer loop
                if(i >= compressed.size()) {
                    break;
                }
                bit_seq = compressed[i++];
                cleared = 0;
            }
            //is first bit set?
            if(bit_seq >= 0x80) {
                node = node->one;
            } else {
                node = node->zero;
            }
            //shift left to adjust most significant bit
            bit_seq = bit_seq << 1;
            cleared++;
        }
        if(os.tellp() >= hTree->text_length) {
            break;
        }
        os << node->val;
    }

    return os.str();
}
