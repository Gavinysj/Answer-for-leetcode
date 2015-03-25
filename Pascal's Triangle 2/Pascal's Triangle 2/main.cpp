//
//  main.cpp
//  Pascal's Triangle 2
//
//  Created by XTBlock on 14/12/14.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    // (n)
    // (k)
    int get_num(int n, int k)
    {
        int tmpval=1;
     
        if (n==0 || k==0 || k==n) {
            return 1;
        }
        
        int tmpk = k;
        
        if (k>n/2) {
            tmpk = n - k;
        }
        tmpval = (long long)n*get_num(n-1, tmpk-1)/tmpk;
        return (int)tmpval;
    }
    
    vector<int> getRow(int rowIndex) {
        vector<int> PascalTriangleRow(0);
        int i=0;
        while (i<=rowIndex) {
            //cout<<"PascalTriangleRow["<<i<<"]="<<get_num(rowIndex, i)<<endl;
            PascalTriangleRow.push_back(get_num(rowIndex, i));
            i++;
        }
        
        return PascalTriangleRow;
    }
};



int main(int argc, const char * argv[]) {
    
    int rowIndex=30;
    Solution test;
    vector<int> tmp = test.getRow(rowIndex);
    
    for (int i=0; i<=rowIndex; i++) {
        cout<<tmp[i]<<" ";
    }
    
    cout<<endl;
    
    return 0;
}
