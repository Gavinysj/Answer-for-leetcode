//
//  main.cpp
//  Path Sum
//
//  Created by XTBlock on 14/12/15.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*

 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
          5
         / \
        4   8
       /   / \
      11  13  4
     /  \      \
    7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 
 
*/
#include <iostream>
using namespace::std;

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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root==NULL) {
            return false;
        }
        
        if (!(root->left || root->right) && sum==root->val)
            return true;
        
        if (this->hasPathSum(root->left, sum-root->val))
            return true;
        if (this->hasPathSum(root->right, sum-root->val))
            return true;
        
        return false;
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
