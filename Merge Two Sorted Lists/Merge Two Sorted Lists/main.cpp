//
//  main.cpp
//  Merge Two Sorted Lists
//
//  Created by XTBlock on 14/12/30.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//


/*
 
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 
 sorted like { 1 2 3 4 ... }
 */


#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        if (l1==NULL) {
            return l2;
        }
        if (l2==NULL) {
            return l1;
        }
        
        ListNode *tmp1=l1, *tmp2=l2;
        
        ListNode *result = NULL;
        ListNode **tmp = &result;
        
        while (tmp1 && tmp2) {
            if (tmp1->val<tmp2->val) {
                *tmp = tmp1;
                tmp1 = tmp1->next;
                tmp = &((*tmp)->next);
            }else
            {
                *tmp = tmp2;
                tmp2 = tmp2->next;
                tmp = &((*tmp)->next);
            }
            
            while (tmp1) {
                *tmp = tmp1;
                break;
            }
            
            while (tmp2) {
                *tmp = tmp2;
                break;
            }
        }
        
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
