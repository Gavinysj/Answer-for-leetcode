//
//  main.cpp
//  Two Sum
//
//  Created by XTBlock on 15/3/23.
//  Copyright (c) 2015年 XTBlock. All rights reserved.
//

/*
 
 Given an array of integers, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 
 */

#include <iostream>
#include <vector>

using namespace::std;

vector<int> twoSum(vector<int> &numbers, int target) {
    
    vector<int> ret(2, 0);
    auto size = numbers.size();
    for(decltype(numbers.size()) i=0; i<size; i++)
    {
        if (numbers[i]==0 || numbers[i]>=target)
            continue;
        for (decltype(numbers.size()) j=(i+1); j<size; j++) {
            if (numbers[j]==0 || numbers[j]>=target)
                continue;
            
            if ((numbers[i]+numbers[j])==target) {
                ret[0] = numbers[i]>numbers[j] ? numbers[j]:numbers[i];
                ret[1] = target - ret[0];
                break;
            }
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
