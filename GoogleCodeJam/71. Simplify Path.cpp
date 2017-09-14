//
//  Add to List 71. Simplify Path.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/2/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"



string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while (getline(ss, tmp, '/')) {
        if(tmp == "" or tmp == ".") continue;
        if(tmp == ".." and !stk.empty()) stk.pop_back();
        else if(tmp != "..")stk.push_back(tmp);
    }
    for(auto str : stk) res += "/" + str;
    return res.empty() ? "/" : res;
}
