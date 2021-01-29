//
// Created by tompa on 28.01.2021.
//

#include "H_Tree.h"
#include <vector>
#include <map>
#include <algorithm>

H_Tree::H_Tree() : root(nullptr), text_length(0) {
}

H_Tree::H_Tree(const std::string &text) : text_length(text.size()) {
//store all nodes as Huffmann tree nodes that occur at least once
    std::vector<std::pair<H_Tree_Node *, int>> nodes;
    //store index of byte in leaf vector
    std::map<char, int> indices;
    int i = 0;

    //increase count for each occurrence
    for (const char &c : text) {
        //create key if not present
        if (!indices.contains(c)) {
            nodes.emplace_back(new H_Tree_Node(c), 0);
            indices[c] = i++;
        }
        //increase count
        nodes[indices[c]].second++;
    }

    //declare custom comparator to sort by count
    auto cmp = [](const std::pair<H_Tree_Node *, int> &a, const std::pair<H_Tree_Node *, int> &b) {
        return a.second > b.second;
    };

    //iteratively merge the two nodes with lowest count
    while (nodes.size() > 1) {

        //sort descending by count
        std::sort(nodes.begin(), nodes.end(), cmp);

        //node with lowest count
        H_Tree_Node *left = nodes.back().first;
        int left_count = nodes.back().second;
        nodes.pop_back();

        //node with second lowest count
        H_Tree_Node *right = nodes.back().first;
        int right_count = nodes.back().second;
        nodes.pop_back();

        //construct parent node
        auto *parent = new H_Tree_Node();

        //set parent-child connections
        parent->zero = left;
        parent->one = right;
        left->parent = parent;
        right->parent = parent;

        //add to node list with combined count
        nodes.emplace_back(parent, left_count + right_count);
    }

    //remaining node is root node of Huffmann tree
    this->root = nodes.back().first;
}

H_Tree::~H_Tree() {
    delete root;
}


std::map<char, std::string> H_Tree::get_bit_sequence_mapping() {
    std::map<char, std::string> seqs;

    //crawl through tree
    root->crawl_bit_seq(seqs);

    return seqs;
}


std::string H_Tree::to_string() {
    return root->to_string(0);
}






