//
// Created by tompa on 28.01.2021.
//

#pragma once

#include <string>
#include <map>

/**
 * A node in a Huffman tree.
 */
class H_Tree_Node {
public:
    /**
     * Constructs an empty node.
     */
    H_Tree_Node();

    /**
     * Constructs a leaf node with the given byte value.
     * @param val The byte value this node should represent.
     */
    H_Tree_Node(char val);

    /**
     * Free all the memory associated with this node and the corresponding subtree
     */
    ~H_Tree_Node();

    /**
     * The left child of this node, corresponding to a zero bit.
     */
    H_Tree_Node *zero;

    /**
     * The right child of this node, corresponding to a one bit.
     */
    H_Tree_Node *one;

    /**
     * The parent node of this node.
     */
    H_Tree_Node *parent;

    /**
     * The potential byte value saved in this node, if it is a leaf node.
     */
    char val;

    /**
     * Crawl through the subtree orginating from this node and collect all found bit sequences
     * that terminate in a leaf node
     *
     * @param mapping The map the bit sequences are stored into
     */
    void crawl_bit_seq(std::map<char, std::string>& mapping);

    /**
     * @param depth the current depth (indentation)
     * @return A string representation of the subtree starting at this node
     */
    std::string to_string(int depth);
};


