//
//  main.cpp
//  Valid Palindrome
//
//  Created by XTBlock on 14/12/14.
//  Copyright (c) 2014年 XTBlock. All rights reserved.
//

#include <iostream>
#include <string>

class Solution {
public:
    
    bool is_alpha(char *ch)
    {
        //std::cout<<"a:z:A:Z -- "<<(int)'a'<<":"<<(int)'z'<<":"<<(int)'A'<<":"<<(int)'Z'<<", "<<(int)'!'<<std::endl;
        
        //int tmp = ch[0];
        
        if ((ch[0]<='z' && ch[0]>='a') || (ch[0]<='9' && ch[0]>='0')) {
            return true;
        }
        else if(ch[0]<='Z' && ch[0]>='A')
        {
            ch[0] = ch[0] + 32;
            return true;
        }
        
        return false;
    }
    
    bool isPalindrome(std::string s) {
        
        int i=0, j=s.length()-1;
        
        bool flag_front;
        bool flag_back;
        
        while (i<j) {
            
            //std::cout<<s[i]<<":"<<i<<std::endl;
            
            flag_front = is_alpha(&(s[i]));
            flag_back = is_alpha(&(s[j]));
            
            //std::cout<<s[i]<<":"<<flag_front<<" "<<s[j]<<":"<<flag_back<<"\n";
            
            if(flag_back && flag_front)
            {
                if (s[i]==s[j])
                {
                    i++;
                    j--;
                }else
                    return false;
                
            }else if (flag_front){
                j--;
            }else if (flag_back){
                i++;
            }
            else {
                i++;
                j--;
            }
        }
        
        return true;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution test;
    
    std::string tmp1 = "A man, a plan, a canal: Panama";
    if (test.isPalindrome(tmp1)) {
        std::cout <<tmp1<<" is palindrome!\n";
    }
    else
        std::cout <<tmp1<<" is not palindrome!\n";
    
    std::string tmp2 = "race a car";
    if (test.isPalindrome(tmp2)) {
        std::cout <<tmp2<<" is palindrome!\n";
    }
    else
        std::cout <<tmp2<<" is not palindrome!\n";
    
    
    // insert code here...
    std::cout <<'a'-'A'<< " success end!\n";
    return 0;
}
