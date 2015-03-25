//
//  main.cpp
//  Remove Duplicates from Sorted List
//
//  Created by XTBlock on 14/12/30.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//


/**
 
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 
 */



#include <iostream>




/**
 * Definition for singly-linked list.
 **/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    
    ListNode *deleteDuplicates(ListNode *head) {
        if (head==NULL) {
            return head;
        }
        
        ListNode *list = head;
        
        while (list->next) {
            if (list->val==list->next->val) {
                ListNode* tmp = list->next;
                list->next = tmp->next;
                delete tmp;
            }else
            {
                list = list->next;
            }
        }
        
        return head;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
