//
//  294.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/19/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


unordered_map<string, bool> hash_map;
bool canWin(string s) {
    int len = s.size();
    if (hash_map.find(s) != hash_map.end()) {
        return hash_map[s];
    }
    bool result = false;
    for (int index = 0; index <= len - 2; index++) {
        if (s[index] == '+' and s[index + 1] == '+') {
            s[index] = '-';
            s[index + 1] = '-';
            result = !canWin(s);
            s[index] = '+';
            s[index + 1] = '+';
            if (result) {
                hash_map[s] = result;
                return true;
            }
        }
    }
    hash_map[s] = result;
    return result;
}





