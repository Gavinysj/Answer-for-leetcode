//
//  main.cpp
//  Number of 1 Bits
//
//  Created by XTBlock on 15/3/25.
//  Copyright (c) 2015年 XTBlock. All rights reserved.
//

/*
 
 Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 
 For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 
 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 
 */


#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned int n=2;
    
    int number=0;
    
    unsigned int i=1;
    
    unsigned int n1=n>>24, n2=(n>>16)&0xff, n3=(n>>8)&0xff, n4=n&0xff;
    
    for(;i<=0xff;)
    {
        std::cout<<(n4&i)<<std::endl;
        number += ((n1&i)+(n2&i)+(n3&i)+(n4&i))/i;
        i*=2;
    }
    
    std::cout <<number<< " Hello, World!\n";
    return 0;
}
