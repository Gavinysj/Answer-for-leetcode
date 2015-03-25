//
//  main.cpp
//  Rotate Array
//
//  Created by XTBlock on 15/3/25.
//  Copyright (c) 2015年 XTBlock. All rights reserved.
//

/*
 
 Rotate an array of n elements to the right by k steps.
 
 For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 
 Note:
 Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 
 [show hint]
 
 Hint:
 Could you do it in-place with O(1) extra space?
 Related problem: Reverse Words in a String II
 
 Credits:
 Special thanks to @Freezen for adding this problem and creating all test cases.
 
 */


#include <iostream>
using namespace::std;

void rotate1(int nums[], int n, int k) {
    
    k=k%n;
    for (int i=0; i<k; i++) {
        nums[n-1-i] = (nums[n-1-i])^(nums[k-1-i]);
        nums[k-1-i] = (nums[n-1-i])^(nums[k-i-i]);
        nums[n-1-i] = (nums[n-1-i])^(nums[k-i-i]);
        cout<<(n-i-1)<<":"<<nums[n-1-i]<<" "<<k-1-i<<":"<<nums[k-i-1]<<endl;
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int input[] = {1,2,3};
    
    rotate1(input, 3, 1);
    
    for (int i=0; i<3; i++) {
        cout<<input[i]<<endl;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
