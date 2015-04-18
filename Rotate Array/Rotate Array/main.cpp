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

void rotate(int nums[], int n, int k) {
    k%=n;
    if(k==0)
        return;
    
    int *tmparray = new int[k];
    int tmpcount = 0;
    for(int i=0; i<k; ++i)
    {
        tmparray[i] = nums[n-k+i];
        tmpcount = (n-k+i)>=k ? n-2*k+i : 2*n-2*k+i;
        nums[n-k+i] = nums[tmpcount];
    }
    
    if (n>2*k) {
        for (int i=0; i<n-2*k; ++i) {
            nums[n-k-i-1] = nums[n-2*k-i-1];
        }
    }
    
    for (int i=0; i<k; ++i) {
        nums[i] = tmparray[i];
    }
    
    delete tmparray;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int input[] = {1,2};
    
    rotate(input, 2, 1);
    
    for (int i=0; i<2; i++) {
        cout<<input[i]<<endl;
    }
    
    //std::cout << "Hello, World!\n";
    return 0;
}
