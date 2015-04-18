//
//  main.cpp
//  House Robber
//
//  Created by XTBlock on 15/4/18.
//  Copyright (c) 2015年 XTBlock. All rights reserved.
//

/*
 You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 
 Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 
 Credits:
 Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
 */

#include <iostream>
#include <vector>
using namespace::std;

//递归
class Solution1 {
public:
    static int get_the_max(vector<int> &num, size_t n)
    {
        switch (n) {
            case 0:
                return 0;
            case 1:
                return num[0];
            case 2:
                return num[0] > num[1] ? num[0] : num[1];
            default:
                int tmp1 = get_the_max(num, n-1);
                int tmp2 = get_the_max(num, n-2)+num[n-1];
                
                return tmp1 > tmp2 ? tmp1 : tmp2;
        }
    }
    
    int rob(vector<int> &num) {
        return get_the_max(num, num.size());
    }
};

//correct
class Solution {
public:
    
    int rob(vector<int> &num) {
        
        size_t n = num.size();
        
        int temp1, temp2;
        
        switch (n) {
            case 0:
                return 0;
            case 1:
                return num[0];
            case 2:
                return num[0] > num[1] ? num[0] : num[1];
            default:
                
                int *rmax = new int[n];
                
                rmax[0] = num[0];
                rmax[1] = num[0] > num[1] ? num[0] : num[1];
                
                for (int i=2; i<n; ++i) {
                    temp1 = num[i]+rmax[i-2];
                    temp2 = rmax[i-1];
                    rmax[i] = temp1>temp2?temp1:temp2;
                }
                
                int ret = rmax[n-1] > rmax[n-2]  ? rmax[n-1] : rmax[n-2];
                
                delete rmax;
                return ret;
        }
    }
};



int main(int argc, const char * argv[]) {
    
    vector<int> test;
    test.push_back(1);
    test.push_back(3);
    test.push_back(1);
    test.push_back(3);
    test.push_back(100);
    
    Solution rob;
    cout<<"result="<<rob.rob(test)<<endl;
    
    return 0;
}
