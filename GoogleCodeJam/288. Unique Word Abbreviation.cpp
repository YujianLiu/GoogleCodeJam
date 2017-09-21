//
//  288.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/19/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


ValidWordAbbr::ValidWordAbbr(vector<string> dictionary) {
    dic  = dictionary;
    unordered_map<string, int> clean;
    for(auto word : dic){
        clean[word]++;
    }
    dic.clear();
    for (auto it = clean.begin(); it != clean.end(); ++it) {
        dic.push_back(it -> first);
    }
    
    for(auto word : dic){
        string temp;
        temp = word.front() + temp + word.back();
        Simple_Dictionary[temp].push_back((int)word.size() - 2);
    }
}

bool ValidWordAbbr:: isUnique(string word) {
    string temp;
    temp = word.front() + temp + word.back();
    int count = 0;
    for (int index = 0; index < Simple_Dictionary[temp].size(); index++) {
        if (Simple_Dictionary[temp][index] == (int)word.size() - 2) {
            count++;
        }
    }
    if (count == 0) {
        return true;
    }
    else if(count == 1){
        for(auto voc : dic){
            if (voc == word) {
                return true;
            }
        }
        return false;
    }else
    return false;
}
