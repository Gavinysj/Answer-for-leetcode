//
//  main.cpp
//  Palindrome Number
//
//  Created by XTBlock on 14/12/15.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//
/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

#include <iostream>
#include <limits.h>
#include <math.h>

using namespace::std;

class Solution {
public:
    bool isPalindrome(int x) {

        if (x<0)
            return false;
        
        if (x/10==0)
            return true;
            
        int n=0, i=0;
        int tmp = x;
        
        while (tmp/10) {
            n++;
            tmp/=10;
        }
        
        cout<<"n:"<<n<<endl;
        
        tmp = x;

        while (n>i) {
            if (tmp/(int)pow(10, n-i)!=tmp%10) {
                cout<<"tmp:"<<tmp<<endl;
                return false;
            }
            tmp%=(int)pow(10, n-i);
            tmp/=10;
            n--;
            i++;
        }
        
        return true;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution test;
    
    
    std::cout <<test.isPalindrome(9999)<<" Hello, World!\n";
    return 0;
}
