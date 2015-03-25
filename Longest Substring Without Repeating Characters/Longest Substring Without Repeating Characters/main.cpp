//
//  main.cpp
//  Longest Substring Without Repeating Characters
//
//  Created by XTBlock on 15/3/23.
//  Copyright (c) 2015年 XTBlock. All rights reserved.
//

/*
 
 Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 
 */

#include <iostream>
#include <string>

using namespace::std;

int lengthOfLongestSubstring(string s) {
    uint64_t size = s.length();
    
    int count, max_length=0, tmp_length=0;
    
    int tmp[256];
    bzero(tmp, 256*sizeof(int));
    
    uint64_t tmp_i = 0;
    
    for (uint64_t i=0; i<size;) {
        count = s[i];
        if (tmp[count]==0) {
            tmp_length++;
            tmp[count]=tmp_length;
            i++;
        }else
        {
            if (max_length<tmp_length) {
                max_length = tmp_length;
            }
            i = tmp_i+tmp[count];
            tmp_i = i;
            bzero(tmp, 256*sizeof(int));
            tmp_length = 0;
        }
    }
    
    max_length = max_length<tmp_length?tmp_length:max_length;
    
    return max_length;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = {"aab"};
    
    int ret = lengthOfLongestSubstring(s);
    
    std::cout << ret<<"\nHello, World!\n";
    return 0;
}
