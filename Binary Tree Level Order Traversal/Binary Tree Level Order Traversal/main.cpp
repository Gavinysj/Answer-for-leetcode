//
//  main.cpp
//  Binary Tree Level Order Traversal
//
//  Created by XTBlock on 14/12/21.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 
 For example:
 Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
        /  \
       15   7
 return its level order traversal as:
 [
    [3],
    [9,20],
    [15,7]
 ]

 */

#include <iostream>
#include <vector>

using namespace::std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root==NULL) {
            return result;
        }
        
        vector<int> line;
        result.push_back(line);
        
        if (root->left==NULL && root->right==NULL) {
            result[0].push_back(root->val);
            return result;
        }
        
        vector<vector<int>> ret_left = levelOrder(root->left);
        vector<vector<int>> ret_right = levelOrder(root->right);
        
        int llen = (int)ret_left.size();
        int rlen = (int)ret_right.size();
        
        //cout<<llen<<", "<<rlen<<endl;
        
        unsigned long len = llen > rlen ? llen : rlen;
        
        for (int i=0; i<len; i++) {
            result.push_back(line);
        }
        
        for (unsigned long i=0; i<len; i++) {
            if (i<llen) {
                for (unsigned long j=0; j<ret_left[i].size(); j++) {
                    result[i+1].push_back(ret_left[i][j]);
                }
            }
            
            if (i<rlen) {
                for (unsigned long j=0; j<ret_right[i].size(); j++) {
                    result[i+1].push_back(ret_right[i][j]);
                }
            }
        }
        
        result[0].push_back(root->val);
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution test;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<vector<int>> ret = test.levelOrder(root);
    
    for (int i=0; i<ret.size(); i++) {
        for (int j=0; j<ret[i].size(); j++) {
            cout<<"ret["<<i<<"]["<<j<<"]="<<ret[i][j]<<", ";
        }
        cout<<endl;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}

