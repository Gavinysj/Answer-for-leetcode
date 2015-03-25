//
//  main.cpp
//  Add Two Numbers
//
//  Created by XTBlock on 15/3/23.
//  Copyright (c) 2015年 XTBlock. All rights reserved.
//

/*

 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 
 */
 
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int tmp=0, tmp_h=0;
        
        ListNode *l1_tmp = l1, *l2_tmp=l2, *l3=NULL, **l3_tmp=&l3;
        
        while (l1_tmp && l2_tmp) {
            
            tmp = l1_tmp->val + l2_tmp->val;
            
            *l3_tmp = new ListNode((tmp+tmp_h)%10);
            l3_tmp = &((*l3_tmp)->next);
            
            tmp_h = (l1_tmp->val + l2_tmp->val+tmp_h)/10;
            l1_tmp = l1_tmp->next;
            l2_tmp = l2_tmp->next;
        }
        
        while (l1_tmp) {
            tmp = l1_tmp->val;
            *l3_tmp = new ListNode((tmp+tmp_h)%10);
            l3_tmp = &((*l3_tmp)->next);
            tmp_h = (l1_tmp->val+tmp_h)/10;
            l1_tmp = l1_tmp->next;
        }
        
        while (l2_tmp) {
            tmp = l2_tmp->val;
            *l3_tmp = new ListNode((tmp+tmp_h)%10);
            l3_tmp = &((*l3_tmp)->next);
            tmp_h = (l2_tmp->val+tmp_h)/10;
            l2_tmp = l2_tmp->next;
        }
        
        if (tmp_h!=0)
            *l3_tmp = new ListNode(tmp_h);
        
        return l3;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution test;
    
    ListNode *temp1=new ListNode(0), *temp2 = new ListNode(0);
    
    ListNode *tmp = test.addTwoNumbers(temp1, temp2);
    
    std::cout << tmp->val <<"\n";
    return 0;
}
