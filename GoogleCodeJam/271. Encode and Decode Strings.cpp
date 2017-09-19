//
//  271. Encode and Decode Strings.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/19/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

string Codec::encode(vector<string>& strs) {
    string result;
    for(auto str : strs){
        for (int index = 0; index < str.size(); index++) {
            int num = str[index];
            string temp = to_string(num);
            while (temp.size() < 3) {
                temp = '0' + temp;
            }
            result += temp;
        }
        if (str.empty()) {
            result += "300";
        }
        result += ' ';
    }
    return result;
}

vector<string>  Codec::decode(string s) {
    vector<string> result;
    stringstream ss(s);
    string temp;
    while (ss >> temp) {
        string candi;
        for (int index = 0; index < temp.size(); index++) {
            if ((index + 1) % 3 == 0) {
                string numstring("");
                numstring = temp.substr(index - 2, 3);
                if (numstring == "300") {
                    candi = "";
                }else
                candi += (char)stoi(numstring);
            }
        }
        result.push_back(candi);
    }
    return result;
}
