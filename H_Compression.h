//
// Created by tompa on 28.01.2021.
//

#pragma once

#include <string>
#include "H_Tree.h"

/**
 * API for text compression using Huffman trees.
 */
class H_Compression {

public:
    /**
     * Compresses a text string using Huffman trees.
     * @param text The string to be compressed.
     * @return A pair containing the Huffman tree and the compressed string
     */
    static std::pair<H_Tree*, std::string> compress(const std::string &text);

    /**
     * Decompresses a given string
     * @param hTree the Huffman tree that was used to compress the string
     * @param compressed The compressed string
     * @return The decompressed string
     */
    static std::string decompress(const H_Tree* hTree, const std::string &compressed);
};


