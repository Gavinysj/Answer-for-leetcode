//
//  main.cpp
//  ZigZag Conversion
//
//  Created by XTBlock on 14/12/14.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*
 
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:
 
 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 
 */

#include <iostream>
#include <string>

using namespace::std;

class Solution{
    
public:
    
    string convert(string text, int nRows)
    {
        if (nRows<=1) {
            return text;
        }
        
        int len = text.length();

        string *tmp = new string[nRows];
        
        int count=0, j=0, flag = 1;
        
        while (count<len) {
            tmp[j].push_back(text[count]);
            count++;
            j+=flag;
            if (j==0)
                flag = 1;
            else if(j==nRows-1)
                flag = -1;
        }
        
        string result;
        for (j=0; j<nRows; j++) {
            result.append(tmp[j]);
        }
        
        delete []tmp;
        return result;
        
        /*
         text.clear();
         for (j=0; j<nRows; j++) {
            text.append(tmp[j]);
         }
         
         delete []tmp;
         return text;
         
         */
    }
    
};




int main(int argc, const char * argv[]) {
    // insert code here...
    Solution test;
    
    string tmp = "PAYPALISHIRING";
    
    std::cout <<test.convert(tmp, 3)<< ", Hello, World!\n";
    return 0;
}
