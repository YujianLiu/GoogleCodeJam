//
//  MinimumWindowSubstring.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

string minWindow(string s, string t) {
    unordered_map<char, int> Chars_In_T;
    string result = "";
    size_t Length_Of_T = t.size(), Length_Of_S = s.size();
    int start = 0, stop = 0, head = 0, size = INT_MAX, Chars_Remain_In_T = (int)Length_Of_T;
    
    for(auto c : t)
    {
        Chars_In_T[c]++;
    }
    
    while (stop < Length_Of_S) {
        
        if(Chars_In_T[s[stop]] > 0)
        {
            Chars_Remain_In_T--;
        }
        
        Chars_In_T[s[stop]]--;
        stop++;
        
        while (Chars_Remain_In_T == 0) {
            
            if(stop - start < size)
            {
                head = start;
                size = stop - start;
            }
            
            Chars_In_T[s[start]]++;
            
            if(Chars_In_T[s[start]] > 0)
            {
                Chars_Remain_In_T++;
            }
        
            start++;
        }
    }
    
    result = size < INT_MAX ? s.substr(head, size) : result;
    
    return result;
}
