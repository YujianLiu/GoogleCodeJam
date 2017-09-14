//
//  186. Reverse Words in a String II.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/7/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int start = 0;
    for(int index = 0; index < s.size(); index++)
    {
        if (s[index] == ' ') {
            reverse(s.begin() + start, s.begin() + index);
            start = index + 1;
        }
    }
    reverse(s.begin() + start, s.end());
}
