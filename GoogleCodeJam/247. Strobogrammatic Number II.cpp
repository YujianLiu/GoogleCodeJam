//
//  247. Strobogrammatic Number II.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/9/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"
int num, flag = 0;
vector<string> findStrobogrammatic(int n) {
    if (flag == 0) {
        num = n;
        flag = 1;
    }
    vector<string> result;
    if (n == 0) {
        result.push_back("");
    }
    else if (n == 1) {
        result.push_back("0");
        result.push_back("1");
        result.push_back("8");
    }
    else {
        vector<string> preres = findStrobogrammatic(n - 2);
        for(auto s : preres){
            if (n != num) {
                 result.push_back("0" + s + "0");
            }
           
            result.push_back("1" + s + "1");
            result.push_back("6" + s + "9");
            result.push_back("9" + s + "6");
            result.push_back("8" + s + "8");
        }
    }
    
    
    return result;
}
