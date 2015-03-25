//
//  main.cpp
//  Add Binary
//
//  Created by XTBlock on 14/12/30.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//



/**
 
 Given two binary strings, return their sum (also a binary string).
 
 For example,
 a = "11"
 b = "1"
 Return "100".
 
 **/

#include <iostream>
#include <string>
using namespace::std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        string c;
        
        size_t alen = a.length();
        size_t blen = b.length();
        
        if (alen==0)
            return b;
        
        if (blen==0)
            return a;
        
        int i=1, carray=0;
        
        while (i<=alen && i<=blen) {
            if (a[alen-i]=='0' && b[blen-i]=='0') {
                c.insert(c.begin(), '0'+carray);
                carray = 0;
            }else if(a[alen-i]=='0' || b[blen-i]=='0')
            {
                c.insert(c.begin(), carray==1 ? '0' : '1');
                carray = carray==1 ? 1 : 0;
            }else
            {
                c.insert(c.begin(), carray==1 ? '1' : '0');
                carray =  1;
            }
            //cout<<"i="<<i<<", carray="<<carray<<", c="<<c<<endl;
            i++;
        }
        
        while (i<=alen) {
            if (a[alen-i]=='0') {
                c.insert(c.begin(), carray==1 ? '1' : '0');
                carray = 0;
            }else
            {
                c.insert(c.begin(), carray==1 ? '0' : '1');
                carray = carray==1 ? 1 : 0;
            }
            i++;
        }
        
        while (i<=blen) {
            if (b[blen-i]=='0') {
                c.insert(c.begin(), carray==1 ? '1' : '0');
                carray = 0;
            }else
            {
                c.insert(c.begin(), carray==1 ? '0' : '1');
                carray = carray==1 ? 1 : 0;
            }
            i++;
        }
        
        if (carray==1) {
            c.insert(c.begin(), '1');
        }
        
        return c;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    string a = "1010";
    string b = "1011";
    
    Solution test;
    string c = test.addBinary(a, b);
    
    std::cout << c <<", Hello, World!\n";
    return 0;
}
