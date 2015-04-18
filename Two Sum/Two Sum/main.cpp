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
    vector<int> tmp;
    auto size = numbers.size();
    
    int count=0;
    
    for (int i=0; i<size; ++i) {
        if (target>=numbers[i]) {
            tmp.push_back(numbers[i]);
            ++count;
        }
    }
    
    size = tmp.size();
    
    if (count==size) {
        count--;
    }
    
    int temp_l, temp_r, temp;
    
    for(int i=0; i<count; ++i)
    {
        temp_r = count;
        temp = count;
        temp_l = 0;
        while (1) {
            //cout<<"["<<i<<"]"<<", temp="<<temp<<", temp_l="<<temp_l<<",temp_r="<<temp_r<<endl;
            if (tmp[i]+tmp[temp]>target) {
                if (temp==temp_l) {
                    break;
                }
                temp_r = temp;
                temp = (temp_l+temp_r)/2;
                if (temp==temp_r) {
                    break;
                }
            }else if(tmp[i]+tmp[temp]<target)
            {
                if (temp==temp_r) {
                    break;
                }
                temp_l = temp;
                temp = (temp_r+temp_l)/2;
                if (temp == temp_l) {
                    break;
                }
            }else
            {
                ret[0] = tmp[i]<tmp[temp]?tmp[i]:tmp[temp];
                ret[1] = tmp[i]>tmp[temp]?tmp[i]:tmp[temp];
                //cout << "ret[0],[1] = " <<ret[0]<<","<<ret[1]<<endl;
                return ret;
            }
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> test;
    test.push_back(0);
    test.push_back(4);
    test.push_back(3);
    test.push_back(0);
    
    vector<int> ret = twoSum(test, 4);
    
    std::cout << ret[0] << " " << ret[1] << endl;
    return 0;
}
