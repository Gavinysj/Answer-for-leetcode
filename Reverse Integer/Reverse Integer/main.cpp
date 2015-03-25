//
//  main.cpp
//  Reverse Integer
//
//  Created by XTBlock on 14/12/14.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//


/*
 
 Reverse digits of an integer.
 
 Example1: x = 123, return 321
 Example2: x = -123, return -321
 
 click to show spoilers.
 
 Have you thought about this?
 Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 
 If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 
 Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 
 For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 
 Update (2014-11-10):
 Test cases had been added to test the overflow behavior.
 
*/

#include <iostream>
#include <limits.h>

class Solution{
public:
    int reverse(int x)
    {
        int tmp_val = x;
        int result = 0;
        
        while (tmp_val/10 && (tmp_val>=10 || tmp_val<=-10)) {
            result = result*10+tmp_val%10;
            tmp_val = tmp_val/10;
        }
        
        //std::cout<<"result = "<<result<<", tmp_val="<<tmp_val<<std::endl;
        
        if (result>INT_MAX/10 || result<INT_MIN/10) {
            return 0;
        }
        
        result = result*10;
        
        //std::cout<<"result = "<<result<<", tmp_val="<<tmp_val<<std::endl;
        
        if ((tmp_val>0 && result>(INT_MAX-tmp_val)) || (tmp_val<0 && result<(INT_MIN-tmp_val))) {
            return 0;
        }
        
        //std::cout<<"result = "<<result<<", tmp_val="<<tmp_val<<std::endl;
        
        result += tmp_val;
        
        return result;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution test;
    int result = test.reverse(-2147483648);
    
    std::cout <<result<<" Hello, World!\n";
    return 0;
}
