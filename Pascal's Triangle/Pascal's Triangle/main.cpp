//
//  main.cpp
//  Pascal's Triangle
//
//  Created by XTBlock on 14/12/14.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> PascalTriangle(numRows, vector<int>(0));
        int j;
        int i=0;
        while (i<numRows) {
            PascalTriangle[i].push_back(1);
            j = 1;
            while (j<i) {
                PascalTriangle[i].push_back(PascalTriangle[i-1][j-1]+PascalTriangle[i-1][j]);
                j++;
            }
            if(i>0)
                PascalTriangle[i].push_back(1);
            
            i++;
        }
        
        return PascalTriangle;
    }
};


int main(int argc, const char * argv[]) {

    Solution test;
    
    int row = 5;
    vector<vector<int>> PascalTriangle = test.generate(row);
    for (int i=0; i<row; i++) {
        
        
        cout<<PascalTriangle[i].size()<<":    ";
        for (int k=0; k<row-i; k++) {
            cout<<" ";
        }
        for (int j=0; j<(i+1); j++) {
            cout<<PascalTriangle[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //cout << "Hello, World!\n";
    return 0;
}
