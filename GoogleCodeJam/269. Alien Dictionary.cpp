//
//  269. Alien Dictionary.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/7/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

string Recursive_269(vector<string>& words);
unordered_map<char, int> Char_Used;

string alienOrder(vector<string>& words) {
    
    string result = "";
    vector<string> Suffix, Same_Pre_Word;
    
    for(auto word : words){
        
        for(auto character : word)
        {
            Char_Used[character] = 0;
        }
        
        //Count the types of all characters, in case there are characters never used.
        
        if(result.empty() || word[0] != result.back())
        {
            if(!Same_Pre_Word.empty() && Same_Pre_Word.size() > 1)
                Suffix.push_back(Recursive_269(Same_Pre_Word));
            
            Same_Pre_Word.clear();
            result += word[0];
            
            if(word.size() > 1)
            Same_Pre_Word.push_back(word.substr(1));
        }
        else if(word[0] == result.back())
        {
            if (word.size() > 1) {
                Same_Pre_Word.push_back(word.substr(1));
            }
        }
        
    }
    if(!Same_Pre_Word.empty() && Same_Pre_Word.size() > 1)
        Suffix.push_back(Recursive_269(Same_Pre_Word));
    
    
    
    
    return  result;
}

string Recursive_269(vector<string>& words){

    string result;
    for(auto word : words)
    {
        
    }
    
    
    return result;
}
