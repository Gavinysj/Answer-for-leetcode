//
//  main.cpp
//  Maximum Depth of Binary Tree
//
//  Created by XTBlock on 14/12/16.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//


/*
 Given a binary tree, find its maximum depth.
 
 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 
 */


#include <iostream>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root==NULL)
            return 0;
        
        if (root->left==NULL && root->right==NULL)
            return 1;
        
        int left = this->maxDepth(root->left)+1;
        int right = this->maxDepth(root->right)+1;
        
        return left>right?left:right;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
