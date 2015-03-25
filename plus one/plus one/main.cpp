//
//  main.cpp
//  plus one
//
//  Created by XTBlock on 14/12/30.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/**
 
 Given a non-negative number represented as an array of digits, plus one to the number.
 
 The digits are stored such that the most significant digit is at the head of the list.
 
 **/

//The Question is this meaning,
//that the digits is a number, and it's number is stored in an array;
//what we should do is plus one for this number;

#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        
        int sum, i;
        int carray = 1;
        
        for (i=digits.size()-1; i>=0; i--) {
            sum = (digits[i]+carray) % 10;
            carray = (digits[i]+carray) / 10;
            
            result.insert(result.begin(), sum);
        }
        
        if (carray==1) {
            result.insert(result.begin(), 1);
        }
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
