//
//  main.cpp
//  Climbing Stairs
//
//  Created by XTBlock on 14/12/30.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*
 
 Question:
 
 You are climbing a stair case. It takes n steps to reach to the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 
 */

#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        
        int n1=1, result=1;
        
        int tmp;
        
        for (int i=2; i<=n; i++) {
            tmp = result;
            result += n1;
            n1 = tmp;
        }
        
        return result;
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        
        if (n==1 || n==2)
            return n;
        
        int t = climbStairs(n-1) + climbStairs(n-2);
        
        return t;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
