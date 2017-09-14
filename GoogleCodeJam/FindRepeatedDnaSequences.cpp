//
//  FindRepeatedDnaSequences.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

/* vector<string> findRepeatedDnaSequences(string s) {
 unordered_set<string> tempResult;
 vector<string> result;
 
 for(size_t i = 0, length = s.length(); i != length - 10; ++i)
 {
 string model = s.substr(i,10);
 string mom = s.substr(i+1);
 if(mom.find(model) != string::npos)
 {
 tempResult.insert(model);
 }
 }
 for(auto it = tempResult.begin(); it!= tempResult.end(); ++it)
 {
 result.push_back(*it);
 }
 return result;
 } */

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    map<int, int> searchTable;
    int t = 0, i = 0, l = s.length();
    while(i < 9)
        t = t << 3 | s[i++] & 7;
    while(i < l)
        if(searchTable[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
            result.push_back(s.substr(i-9,10));
    
    
    return result;
}


