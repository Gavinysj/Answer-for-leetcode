//
//  main.cpp
//  Minimum Depth of Binary Tree
//
//  Created by XTBlock on 14/12/15.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*
 Given a binary tree, find its minimum depth.
 
 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        if (root==NULL)
            return 0;
        
        if (root->left==NULL && root->right==NULL)
            return 1;
        
        if (root->left==NULL)
            return 1+this->minDepth(root->right);
        else if (root->right==NULL)
            return 1+this->minDepth(root->left);
        
        int left = this->minDepth(root->left)+1;
        int right = this->minDepth(root->right)+1;
        
        return left>right?right:left;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
