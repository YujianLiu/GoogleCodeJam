//
//  159. Longest Substring with At Most Two Distinct Characters.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/6/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> Statistic_Chars_S;
    int Size_Of_S = (int) s.size();
    int Index = 0, Start_Of_Substring = 0, Size_Of_Substring = 0, counter = 0;
    
    while (Index < Size_Of_S) {
        
        if(Statistic_Chars_S[s[Index++]]++ == 0)counter++;
        
        while (counter > 2) {
            
            if(Statistic_Chars_S[s[Start_Of_Substring++]]-- == 1)
            {
                counter--;
            }
        }
        Size_Of_Substring = max(Size_Of_Substring, Index - Start_Of_Substring);
    }
    return Size_Of_Substring;
}
