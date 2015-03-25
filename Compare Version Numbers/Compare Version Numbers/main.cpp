//
//  main.cpp
//  Compare Version Numbers
//
//  Created by XTBlock on 14/12/16.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//
/*
 
 Compare two version numbers version1 and version1.
 If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 
 You may assume that the version strings are non-empty and contain only digits and the . character.
 The . character does not represent a decimal point and is used to separate number sequences.
 For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 
 Here is an example of version numbers ordering:
 
 0.1 < 1.1 < 1.2 < 13.37
 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 
 
 
 */



#include <iostream>
#include <string>
using namespace::std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int len1 = version1.length();
        int len2 = version2.length();
        
        int v1_tmp, v2_tmp;
        int i=0, j=0;
        int flag = 0;
        while (i<len1&&j<len2) {
            v1_tmp = 0;
            v2_tmp = 0;
            
            while (i<len1 && version1[i]!='.') {
                v1_tmp += v1_tmp*10 + (char)version1[i]-'0';
                i++;
            }
            
            i++;
            
            while (j<len2 && version2[j]!='.') {
                v2_tmp += v2_tmp*10 + (char)version2[j]-'0';
                j++;
            }
            
            j++;
            
            //cout<<"v1="<<v1_tmp<<", v2="<<v2_tmp<<endl;
            //cout<<"i="<<i<<", j="<<j<<endl;
            
            if (v1_tmp>v2_tmp)
                return 1;
            else if(v1_tmp<v2_tmp)
                return -1;
        }
        
        while (i<len1)
        {
            v1_tmp = 0;
            while (i<len1 && version1[i]!='.') {
                v1_tmp += v1_tmp*10 + (char)version1[i]-'0';
                i++;
            }
            i++;
            
            if (v1_tmp>0)
                return 1;
        }
        
        while (j<len2)
        {
            v2_tmp = 0;
            while (j<len2 && version2[j]!='.') {
                v2_tmp += v2_tmp*10 + (char)version2[j]-'0';
                j++;
            }
            
            j++;
            if (v2_tmp>0) {
                return -1;
            }
        }
        
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution test;
    
    string s1 = "1.0";
    string s2 = "1";
    int tmp = test.compareVersion(s1, s2);
    
    std::cout << tmp << " Hello, World!\n";
    return 0;
}
