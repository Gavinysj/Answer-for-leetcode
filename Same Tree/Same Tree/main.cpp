//
//  main.cpp
//  Same Tree
//
//  Created by XTBlock on 14/12/30.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*
 
 Given two binary trees, write a function to check if they are equal or not.
 
 Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p==NULL && q==NULL)
            return true;
        if (p==NULL || q==NULL)
            return false;
        
        if (p->val==q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
