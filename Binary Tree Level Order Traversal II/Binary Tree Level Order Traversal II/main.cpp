//
//  main.cpp
//  Binary Tree Level Order Traversal II
//
//  Created by XTBlock on 14/12/21.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 
 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its bottom-up level order traversal as:
 [
    [15,7],
    [9,20],
    [3]
 ]
 confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 
 
 OJ's Binary Tree Serialization:
 The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
 
 Here's an example:
        1
       / \
      2   3
         /
        4
         \
          5
 The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
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
        
        vector<vector<int>> ret_left = levelOrderBottom(root->left);
        vector<vector<int>> ret_right = levelOrderBottom(root->right);
        
        int llen = (int)ret_left.size();
        int rlen = (int)ret_right.size();
        
        //cout<<llen<<", "<<rlen<<endl;
        
        unsigned long len = llen > rlen ? llen : rlen;
        
        for (int i=0; i<len; i++) {
            result.push_back(line);
        }
        
        for (unsigned long i=len; i>0; i--) {
            if (llen>0) {
                for (unsigned long j=0; j<ret_left[llen-1].size(); j++) {
                    result[i-1].push_back(ret_left[llen-1][j]);
                }
            }
            
            if (rlen>0) {
                for (unsigned long j=0; j<ret_right[rlen-1].size(); j++) {
                    result[i-1].push_back(ret_right[rlen-1][j]);
                }
            }
            
            llen--; rlen--;
        }
        
        result[len].push_back(root->val);
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution test;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->left->left = new TreeNode(5);
    vector<vector<int>> ret = test.levelOrderBottom(root);
    
    for (int i=0; i<ret.size(); i++) {
        for (int j=0; j<ret[i].size(); j++) {
            cout<<"ret["<<i<<"]["<<j<<"]="<<ret[i][j]<<", ";
        }
        cout<<endl;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
