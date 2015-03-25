//
//  main.cpp
//  String to Integer
//
//  Created by XTBlock on 14/12/14.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

#include <iostream>
#include <limits.h>

class Solution {
public:
    
    int atoi(const char *str) {
        if (str==NULL) {
            return 0;
        }
        
        int len = strlen(str);
        int i=0;
        
        int tmp_num=0;
        bool space_flag;
        
        space_flag = str[i]==' ' ? true : false;
        
        while (space_flag) {
            i++;
            space_flag = str[i]==' ' ? true : false;
            if (i==len) {
                return 0;
            }
        }
        
        bool num_flag;
        
        if (str[i]=='+') {
            i++;
            num_flag = (str[i]>='0' && str[i]<='9') ? true : false;
            while (num_flag && i<len) {
                
                if (INT_MAX/10<tmp_num || (INT_MAX-tmp_num*10)<(str[i]-'0')) {
                    return INT_MAX;
                }
                tmp_num = tmp_num*10 + (str[i]-'0');
                i++;
                num_flag = (str[i]>='0' && str[i]<='9') ? true : false;
            }
            
        }else if(str[i]=='-') {
            i++;
            num_flag = (str[i]>='0' && str[i]<='9') ? true : false;
            while (num_flag && i<len) {
                if (INT_MIN/10>tmp_num || (INT_MIN-tmp_num*10)>('0'-str[i])) {
                    return INT_MIN;
                }
                tmp_num = tmp_num*10 - (str[i]-'0');
                i++;
                num_flag = (str[i]>='0' && str[i]<='9') ? true : false;
            }
            
        }else {
            num_flag = (str[i]>='0' && str[i]<='9') ? true : false;
            while (num_flag && i<len) {
                
                if (INT_MAX/10<tmp_num || (INT_MAX-tmp_num*10)<(str[i]-'0')) {
                    return INT_MAX;
                }
                tmp_num = tmp_num*10 + (str[i]-'0');
                i++;
                num_flag = (str[i]>='0' && str[i]<='9') ? true : false;
            }
        }
        return tmp_num;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    char str[] = "     -21474";
    
    Solution test;
    
    std::cout <<test.atoi(str)<<" Hello, World!\n";
    return 0;
}
