//
//  main.cpp
//  Balanced Binary Tree
//
//  Created by XTBlock on 14/12/15.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*
 
 Given a binary tree, determine if it is height-balanced.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    
    int minDepth(TreeNode *root)
    {
        if (root==NULL) {
            return 0;
        }
        
        if (root->left==NULL || root->right==NULL)
            return 1;
        
        int left = this->minDepth(root->left)+1;
        int right = this->minDepth(root->right)+1;
        
        return left>right?right:left;
    }
    
    int maxDepth(TreeNode *root) {
        if (root==NULL)
            return 0;
        
        if (root->left==NULL && root->right==NULL)
            return 1;
        
        int left = this->maxDepth(root->left)+1;
        int right = this->maxDepth(root->right)+1;
        
        return left>right?left:right;
    }
    
    bool isBalanced(TreeNode *root) {
        if (root==NULL)
            return true;
        
        if (root->left==NULL && root->right==NULL) {
            return true;
        }
        else if (root->left==NULL) {
            return this->maxDepth(root->right)>1?false:true;
        }else if(root->right==NULL)
        {
            return this->maxDepth(root->left)>1?false:true;
        }
        
        int leftdepth = this->maxDepth(root->left);
        int rightdepth = this->maxDepth(root->right);
        
        if (abs(leftdepth-rightdepth)>1)
            return false;
        
        if (!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        
        return true;
    }
};

void generateTree(TreeNode *root, int val, int depth)
{
    if (depth==0) {
        root=NULL;
        return;
    }
    root = new TreeNode(val);
    generateTree(root->left, val+1, depth-1);
    if (depth!=1) {
        generateTree(root->right, val+1, depth-1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode *root;
    generateTree(root, 1, 5);
    
    Solution test;
    bool flag = test.isBalanced(root);
    
    std::cout << flag << " Hello, World!\n";
    return 0;
}
