//
//  479.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/24/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

long BuildPalindrome(int n){
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stol(to_string(n) + s);
}

int largestPalindrome(int n) {
    if (n == 1) {
        return 9;
    }
    int upper = pow(10, n) - 1;
    int lower = pow(10, n - 1);
    for(int index = upper; index >= lower; index--){
        long candidate = BuildPalindrome(index);
        for (long j = upper; j * j >= candidate; j--) {
            if (candidate % j == 0 and candidate / j <= upper) {
                return candidate % 1337;
            }
        }
    }
    return -1;
}
