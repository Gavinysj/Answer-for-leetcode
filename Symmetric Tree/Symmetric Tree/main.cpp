//
//  main.cpp
//  Symmetric Tree
//
//  Created by XTBlock on 14/12/21.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 
 For example, this binary tree is symmetric:
 
        1
       / \
      2   2
     / \ / \
    3  4 4  3
 But the following is not:
        1
       / \
       2  2
       \   \
        3   3
 Note:
 Bonus points if you could solve it both recursively and iteratively.

 */

#include <iostream>
using namespace::std;

/**
 * Definition for binary tree
 * 
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool matchLeftRight(TreeNode *lTree, TreeNode *rTree)
    {
        
        if (lTree->val!=rTree->val)
            return false;
        
        if (lTree->left!=NULL && rTree->right!=NULL && !matchLeftRight(lTree->left, rTree->right))
            return false;
        
        if(lTree->right!=NULL && rTree->left!=NULL && !matchLeftRight(lTree->right, rTree->left))
            return false;
        
        if((rTree->left==NULL && lTree->right!=NULL) || (rTree->left!=NULL && lTree->right==NULL))
            return false;
        if(((lTree->left==NULL) && rTree->right!=NULL) || ((lTree->left!=NULL) && rTree->right==NULL))
            return false;
        
        return true;
    }
    
    bool isSymmetric(TreeNode *root) {
        if (root==NULL)
            return true;
        
        if (root->left==NULL && root->right==NULL) {
            return true;
        }
        if (root->left!=NULL && root->right!=NULL)
            return matchLeftRight(root->left, root->right);
        
        return false;
    }
};

class Solution2 {
public:
    
    bool matchLeftRight(TreeNode *lTree, TreeNode *rTree)
    {
        if (lTree==NULL && rTree==NULL)
            return true;
        
        if (lTree==NULL || rTree==NULL)
            return false;
        
        if (lTree->val==rTree->val)
            return matchLeftRight(lTree->left, rTree->right) && matchLeftRight(lTree->right, rTree->left);
        else return false;
    }
    
    bool isSymmetric(TreeNode *root) {
        if (root==NULL)
            return true;
        return matchLeftRight(root->left, root->right);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
