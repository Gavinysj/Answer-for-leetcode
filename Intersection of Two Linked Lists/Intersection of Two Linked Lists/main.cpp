//
//  main.cpp
//  Intersection of Two Linked Lists
//
//  Created by XTBlock on 14/12/14.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengtha = 0;
        int lengthb = 0;
        
        ListNode *tmpa = headA;
        ListNode *tmpb = headB;
        
        while (tmpa) {
            tmpa = tmpa->next;
            lengtha++;
            if (tmpb) {
                tmpb = tmpb->next;
                lengthb++;
            }
        }
        
        while (tmpb) {
            tmpb = tmpb->next;
            lengthb++;
        }
        
        bool flag = lengthb>lengtha ? true : false;
        
        int gap_count = flag ? lengthb-lengtha : lengtha-lengthb;
        
        tmpa = headA;
        tmpb = headB;
        if (flag) {
            int i=gap_count;
            while (i) {
                tmpb=tmpb->next;
                i--;
            }
            
            while (tmpa) {
                if (tmpa == tmpb) {
                    return tmpa;
                }
                tmpa = tmpa->next;
                tmpb = tmpb->next;
            }
        }
        else
        {
            int i=gap_count;
            while (i) {
                tmpa=tmpa->next;
                i--;
            }
            
            while (tmpa) {
                if (tmpa == tmpb) {
                    return tmpa;
                }
                tmpa = tmpa->next;
                tmpb = tmpb->next;
            }
        }
        
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    
    int a=3, b=2, c=3;
    
    ListNode *lista = new ListNode(0);
    ListNode *listb = new ListNode(10);
    ListNode *listc = new ListNode(20);
    
    ListNode *currentList = lista;
    
    for (int i=0; i<a; i++) {
        ListNode *tmp = new ListNode(i+1);
        currentList->next = tmp;
        currentList = currentList->next;
    }
    currentList->next = listc;
    
    currentList = listb;
    for (int i=0; i<b; i++) {
        ListNode *tmp = new ListNode(i+11);
        currentList->next = tmp;
        currentList = currentList->next;
    }
    
    currentList->next = listc;
    
    currentList = listc;
    for (int i=0; i<b; i++) {
        ListNode *tmp = new ListNode(i+21);
        currentList->next = tmp;
        currentList = currentList->next;
    }
    currentList = NULL;
    
    Solution function;
    
    currentList = function.getIntersectionNode(lista, listb);
    
    std::cout << currentList->val <<" success end!\n";
    return 0;
}






