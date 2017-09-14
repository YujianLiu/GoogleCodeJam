//
//  676. Implement Magic Dictionary.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/9/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        Dictionary.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        Dictionary = dict;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto sample : Dictionary){
            if(sample.size() != word.size())
                continue;
            else{
                int modified = 0;
                for(int index = 0; index < sample.size() && modified < 3; ++index){
                    if (word[index] != sample[index]) {
                        modified++;
                    }
                }
                if(modified == 1)
                    return true;
                
            }
        }
        return false;
    }
private:
    vector<string> Dictionary;
    
};
