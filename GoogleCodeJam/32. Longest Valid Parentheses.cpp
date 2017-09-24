//
//  32. Longest Valid Parentheses.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/30/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//
/*
 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 
 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include "Header.h"


int longestValidParentheses(string s) {
    stack<int> posOfValid;
    size_t stringSize = s.length();
    int result = 0;
    for(int i = 0; i < stringSize; i++)
    {
        if(s[i] == '(')
            posOfValid.push(i);
        else
        {
            if(!posOfValid.empty())
            {
                if(s[posOfValid.top()] == '(')posOfValid.pop();
                else posOfValid.push(i);
            }
            else posOfValid.push(i);
        }
    }
    if(posOfValid.empty())result = stringSize;
    else{
        int a = stringSize, b = 0;
        while (!posOfValid.empty()) {
            b = posOfValid.top();
            posOfValid.pop();
            result = max(result, a - b - 1);
            a = b;
        }
        result = max(result, a);
    }
    return result;
}


/*for(int index = 0; index < stringSize; index++)
 {
 map<char, int> numOfParentheses;
 if (s[index] == '(') {
 for (int i = index; i < stringSize; ++i) {
 numOfParentheses[s[i]]++;
 if(numOfParentheses['('] < numOfParentheses[')'])
 break;
 else if(numOfParentheses['('] == numOfParentheses[')'])
 result = max(result, i - index + 1);
 }
 }
 }*/
