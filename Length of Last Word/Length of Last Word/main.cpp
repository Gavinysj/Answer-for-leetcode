//
//  main.cpp
//  Length of Last Word
//
//  Created by XTBlock on 14/12/30.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*
 
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
 Note: A word is defined as a character sequence consists of non-space characters only.
 
 For example,
 Given s = "Hello World",
 return 5.
 
 */


#include <iostream>
#include <string>
using namespace::std;


class Solution {
public:
    int lengthOfLastWord(const char *s) {
        
        int result = 0;
        
        if (s==NULL) {
            return result;
        }
        
        int start=0;
        int flag = 0;
        
        int i = 0;
        
        while (s[i]!='\0') {
            if (s[i]!=' ' && flag==0) {
                start = i;
                flag = 1;
            }
            if (s[i]==' ' && flag==1) {
                result = i - start;
                flag = 0;
            }
            i++;
        }
        
        if (flag==1) {
            result = i - start;
        }
        
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
