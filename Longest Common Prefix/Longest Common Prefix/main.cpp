//
//  main.cpp
//  Longest Common Prefix
//
//  Created by XTBlock on 15/3/24.
//  Copyright (c) 2015年 XTBlock. All rights reserved.
//

/*
 
 Write a function to find the longest common prefix string amongst an array of strings.
 
 */

#include <iostream>
#include <vector>

using namespace::std;

string longestCommonPrefix(vector<string> &strs) {
    auto size = strs.size();
    string result;
    if (size==0) {
        return result;
    }
    
    auto length0 = strs[0].length();
    int j=0;
    bool flag = true;
    
    
    while (flag && j<length0) {
        for (decltype(size) i=1; i<size; i++) {
            
            if (j==strs[i].length() || strs[i][j]!=strs[0][j]) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            result.push_back(strs[0][j]);
        }
        
        j++;
    }
    
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << longestCommonPrefix(<#vector<string> &strs#>)<<"\n";
    return 0;
}
