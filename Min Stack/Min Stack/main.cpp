//
//  main.cpp
//  Min Stack
//
//  Created by XTBlock on 14/12/14.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

#include <iostream>
#include "MinStack.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    MinStack *minstack = new MinStack();
    
    minstack->push(-1);
    minstack->push(0);
    minstack->push(-1);
    minstack->push(-2);
    std::cout <<minstack->getMin()<<" "<<minstack->top()<<std::endl;
    minstack->pop();
    std::cout <<minstack->getMin()<<" "<<minstack->top()<<std::endl;
    minstack->pop();
    std::cout <<minstack->getMin()<<" "<<minstack->top()<<std::endl;
    minstack->pop();
    std::cout <<minstack->getMin()<<" "<<minstack->top()<<" success end!\n";
    return 0;
}


