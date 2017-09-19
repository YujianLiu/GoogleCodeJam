//
//  267. Palindrome Permutation II.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/19/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


vector<string> makeString(unordered_map<char, int>& Alphabet, string Prev_String){
    
    vector<string> result;
    int count = 0;
    for (auto character = Alphabet.begin(); character != Alphabet.end(); ++character) {
        if (character -> second != 0) {
            count++;
            vector<string> temp_result;
            string New_String = Prev_String;
            char Char_To_Add = character -> first;
            
            New_String = Char_To_Add + Prev_String + Char_To_Add;
            character -> second -= 2;
            
            temp_result = makeString(Alphabet, New_String);
            result.insert(result.end(), temp_result.begin(), temp_result.end());
            character -> second += 2;
        }
    }
    if (count == 0) {
        result.push_back(Prev_String);
    }
    
    return result;
}

vector<string> generatePalindromes(string s) {
    int count = 0;
    unordered_map<char, int> Alphabet;
    vector<string> result;
    string temp;
    
    for (int index = 0; index < s.size(); index++) {
        Alphabet[s[index]]++;
        if (Alphabet[s[index]] % 2 == 1) {
            count++;
        }
        else
            count--;
    }
    
    if (count == 1) {
        for (auto it = Alphabet.begin(); it != Alphabet.end(); ++it) {
            if (it -> second % 2 == 1) {
                
                temp.push_back(it -> first);
                it -> second--;
                result = makeString(Alphabet, temp);
            }
        }
        
    }else if (count == 0){
        result = makeString(Alphabet, temp);
    }
    
    return result;
    
    
}


/*
 vector<string> result;
 sort(s.begin(), s.end());
 do{
 auto start = s.begin(), end = s.end() - 1;
 while (start < end) {
 if (*start == *end) {
 start++;
 end--;
 }
 else
 break;
 }
 if (!(start < end)) {
 result.push_back(s);
 }
 } while (next_permutation(s.begin(), s.end())) ;
 return result;
 
 
 */
