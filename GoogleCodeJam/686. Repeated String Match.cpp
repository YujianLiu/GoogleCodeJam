//
//  686.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/30/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int repeatedStringMatch(string A, string B) {
    int result = 1;
    string s1 = A, s2;
    
    while(s1.size() < B.size()) {
        s1 += A;
        result++;
    }
    for (int i = 0; i <= s1.size() - B.size(); i++) {
        int j = 0, k = i;
        while (j < B.size()) {
            if (s1[k] == B[j]) {
                j++;
                k++;
            }
            else break;
        }
        if (j == B.size()) {
            return result;
        }
    }
    s2 = s1 + A;
    result++;
    for (int i = 0; i <= s2.size() - B.size(); i++) {
        int j = 0, k = i;
        while (j < B.size()) {
            if (s2[k] == B[j]) {
                j++;
                k++;
            }
            else break;
        }
        if (j == B.size()) {
            return result;
        }
    }
    
    return -1;
}
