//
//  main.cpp
//  Merge Sorted Array
//
//  Created by XTBlock on 14/12/30.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

/*
 
 Given two sorted integer arrays A and B, merge B into A as one sorted array.
 
 Note:
 You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */

#include <iostream>

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *C = new int[m+n];
        
        int k=0, i=0, j=0;
        while (k<(m+n) && i<m && j<n) {
            
            if (A[0]<=A[m-1] && B[0]<=B[n-1]) {
                C[k] = A[i] < B[j] ? A[i++] : B[j++];
            }
            else
            {
                C[k] = A[i] > B[j] ? A[i++] : B[j++];
            }
            k++;
        }
        
        while (i<m) {
            C[k] = A[i++];
            k++;
        }
        
        while (j<n) {
            C[k] = B[j++];
            k++;
        }
        
        k=0;
        while (k<(m+n)) {
            A[k] = C[k];
            k++;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
