//
// Created by tompa on 28.01.2021.
//

#include "H_Tree_Node.h"
#include <sstream>

H_Tree_Node::H_Tree_Node() : one(nullptr), zero(nullptr), parent(nullptr), val(0) {
}

H_Tree_Node::H_Tree_Node(char val) : one(nullptr), zero(nullptr), parent(nullptr), val(val) {
}

H_Tree_Node::~H_Tree_Node() {
    if(!val) {
        //No leaf node
        delete zero;
        delete one;
    }
}


std::string H_Tree_Node::to_string(int depth) {

    std::ostringstream os;

    //Is this a leaf node?
    if(val) {
        //Yes, we simply return our character
        os << std::string(depth, '-') << val << std::endl;
    } else {
        //No, we recursively call to_string on our children
        os << std::string(depth, '-') << "0:"<< std::endl
        << zero->to_string(depth + 1)
        << std::string(depth, '-') << "1:" << std::endl
        << one->to_string(depth + 1);
    }

    return os.str();
}

void H_Tree_Node::crawl_bit_seq(std::map<char, std::string>& mapping) {
    if(val) {
        //raeched leaf node, climb back up to root node and remember path
        std::string s;
        H_Tree_Node* node = this;
        while(node->parent) {
            s = (node == node->parent->zero ? "0" : "1") + s;
            node = node->parent;
        }
        mapping[val] = s;
    } else {
        //traverse left and right subtrees
        zero->crawl_bit_seq(mapping);
        one->crawl_bit_seq(mapping);
    }
}



