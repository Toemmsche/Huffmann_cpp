//
// Created by tompa on 28.01.2021.
//

#pragma once

#include <string>
#include "H_Tree_Node.h"
#include <map>

/**
 * The Huffman Tree as a result of the encoding.
 */
class H_Tree {
public:
    /**
     * Construct an empty Huffman Tree
     */
    H_Tree();

    /**
     * Construct a Huffman Tree for a given text string
     * @param The text to be compressed
     */
    explicit H_Tree(const std::string &text);

    /**
     * Free all the memory associated with this Huffman tree
     */
    ~H_Tree();

    /**
     * @return A mapping from each character contained in this Huffman tree to the corresponding bit sequence
     */
    std::map<char, std::string> get_bit_sequence_mapping();

    /**
     * @return A string representation of this Huffman tree
     */
    std::string to_string();

    /**
     * The root node of this tree.
     */
    H_Tree_Node *root;

    /**
     * The length of the string this Huffman tree was constructed from.
     */
    int text_length;
};


