//
//  320.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/20/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

void Recursive_320(vector<string>& result, string word, int pos, int count, string cur){
    if(pos == word.size()){
        if (count > 0) cur += to_string(count);
        result.push_back(cur);
    }
    else{
        Recursive_320(result, word, pos + 1, count + 1, cur);
        Recursive_320(result, word, pos + 1, 0, cur + (count == 0 ? "" : to_string(count)) + word[pos]);
    }
    
}

vector<string> generateAbbreviations(string word) {
    vector<string> result;
    Recursive_320(result, word, 0, 0, "");
    return result;
}
