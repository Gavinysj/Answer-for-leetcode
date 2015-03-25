//
//  main.cpp
//  Roman to Integer
//
//  Created by XTBlock on 14/12/15.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*
 Given a roman numeral, convert it to an integer.
 
 Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <string>


using namespace::std;

class Solution {
public:
    int romanToInt(string s) {
        
        int len = s.length();
        
        if (len==0) {
            return 0;
        }
        
        int romanNum=0;
        int formerSum=0;
        
        for (int i=0; i<len; i++) {
            if (s[i]=='M') {
                formerSum += romanNum<1000 ? -romanNum : romanNum;
                romanNum = 1000;
            }else if(s[i]=='D')
            {
                formerSum += romanNum<500 ? -romanNum : romanNum;
                romanNum = 500;
            }else if(s[i]=='C')
            {
                formerSum += romanNum<100 ? -romanNum : romanNum;
                romanNum = 100;
            }else if(s[i]=='L')
            {
                formerSum += romanNum<50 ? -romanNum : romanNum;
                romanNum = 50;
            }else if(s[i]=='X')
            {
                formerSum += romanNum<10 ? -romanNum : romanNum;
                romanNum = 10;
            }else if(s[i]=='V')
            {
                formerSum += romanNum<5 ? -romanNum : romanNum;
                romanNum = 5;
            }else if(s[i]=='I')
            {
                formerSum += romanNum<1 ? -romanNum : romanNum;
                romanNum = 1;
            }
        }
        
        formerSum+=romanNum;
        
        return formerSum;
        
    }
};

int main(int argc, const char * argv[]) {
    
    Solution test;
    string roman = "";
    // insert code here...
    std::cout <<test.romanToInt(roman)<<" Hello, World!\n";
    return 0;
}
