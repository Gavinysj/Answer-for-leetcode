//
//  MinStack.cpp
//  Min Stack
//
//  Created by XTBlock on 14/12/14.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//


#include <string.h>
#include <limits.h>
#include "MinStack.h"


void MinStack::push(int x)
{
    if (stack_top.empty()) {
        stack_min.push(x);
        stack_top.push(x);
    }else
    {
        stack_top.push(x);
        if(x<=stack_min.top())
            stack_min.push(x);
    }
    /*
    if (!m_ptop) {
        m_nmin = x;
        m_ptop = new MINSTACK(0);
    }else
    {
        int tmp_gap = x - m_nmin;
        MINSTACK *tmp = new MINSTACK(tmp_gap);
        tmp->next = m_ptop;
        m_ptop = tmp;
        
        if (tmp_gap<0) {
            m_nmin = x;
        }
    }
     */
}

void MinStack::pop() {
    if (stack_top.empty()) {
        return;
    }
    
    if (stack_top.top()==stack_min.top()) {
        stack_min.pop();
    }
    
    stack_top.pop();
}

int MinStack::top() {

    if (stack_top.empty()) {
        return 0;
    }
    
    return stack_top.top();
}

int MinStack::getMin() {
    if (stack_min.empty()) {
        return 0;
    }
    return stack_min.top();
}