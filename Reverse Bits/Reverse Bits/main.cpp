//
//  main.cpp
//  Reverse Bits
//
//  Created by XTBlock on 15/3/25.
//  Copyright (c) 2015年 XTBlock. All rights reserved.
//

/*
 
 Reverse bits of a given 32 bits unsigned integer.
 
 For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 
 Follow up:
 If this function is called many times, how would you optimize it?
 
 Related problem: Reverse Integer
 
 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 
 */

#include <iostream>

uint32_t reverseBits(uint32_t n) {
    uint8_t i=0x80;
    uint32_t result=0;
    
    uint8_t n1=n>>24, n2=(n>>16)&0xff, n3=(n>>8)&0xff, n4=n&0xff;
    uint8_t r1=0, r2=0, r3=0, r4=0;
    
    for(int j=0; j<8; j++)
    {
        r1 += ((n1>>j)&0x1)*i;
        r2 += ((n2>>j)&0x1)*i;
        r3 += ((n3>>j)&0x1)*i;
        r4 += ((n4>>j)&0x1)*i;
        i/=2;
    }
    
    result = (r4<<24) | (r3<<16) | (r2<<8) | r1;
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout <<reverseBits((uint32_t)1)<< " Hello, World!\n";
    return 0;
}
