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
     * @return The compressed string
     */
    static std::string compress(const std::string &text);

    /**
     * Decompresses a given string
     * @param compressed
     * @return The decompressed string
     */
    static std::string decompress(const std::string &compressed);
};


