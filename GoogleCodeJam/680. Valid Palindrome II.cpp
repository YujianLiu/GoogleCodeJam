//
//  680. Valid Palindrome II.cpp
//  GoogleCodeJam
//
//  Created by liuyujian on 9/16/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


bool validPalindrome(string s) {
    string S_Temp = s;
    reverse(S_Temp.begin(), S_Temp.end());
    if(s == S_Temp)
        return true;
    int start = 0 , tail = s.size() - 1;
    while (start < tail) {
        if (s[start] != s[tail]) {
            S_Temp = s.substr(start, tail - start);
            string S_Temp_2 = S_Temp;
            reverse(S_Temp.begin(), S_Temp.end());
            if(S_Temp == S_Temp_2)
                return true;
            else{
                S_Temp = s.substr(start + 1, tail - start);
                S_Temp_2 = S_Temp;
                reverse(S_Temp.begin(), S_Temp.end());
                if (S_Temp == S_Temp_2) {
                    return true;
                }
                return false;
            }
            
        }
        else{
            start++;
            tail--;
        }
    }
    return  true;
}
