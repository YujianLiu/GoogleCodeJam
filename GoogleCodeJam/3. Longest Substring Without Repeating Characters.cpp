//
//  3.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/27/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//
/*
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 
 Given "abcabcbb", the answer is "abc", which the length is 3.
 
 Given "bbbbb", the answer is "b", with the length of 1.
 
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
#include "Header.h"

int lengthOfLongestSubstring(string s){
    int result = 0, left = 0, right = 0;
    unordered_map<char, int> alphabet;
    while (right < s.size()) {
        if(alphabet[s[right]] == 0){
            result = max(result, right - left + 1);
            alphabet[s[right]]++;
            right++;
           
        }
        else{
            alphabet[s[left]]--;
            left++;
        }
    }
    return result;
}
