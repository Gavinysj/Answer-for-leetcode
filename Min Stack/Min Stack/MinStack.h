//
//  MinStack.h
//  Min Stack
//
//  Created by XTBlock on 14/12/14.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

#ifndef __Min_Stack__MinStack__
#define __Min_Stack__MinStack__

#include <stdio.h>
#include <stack>
/*
typedef struct _MINSTACK{
    int val;
    _MINSTACK *next;
    _MINSTACK(int x) : val(x), next(NULL) {}
}MINSTACK;
*/

class MinStack {
    
    //MINSTACK *m_ptop;
    std::stack<int> stack_top;
    std::stack<int> stack_min;
    
public:
    
    void push(int x);
    
    void pop();
    
    int top();
    
    int getMin();
};

#endif /* defined(__Min_Stack__MinStack__) */
