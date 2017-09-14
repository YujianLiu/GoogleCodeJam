//
//  358. Rearrange String k Distance Apart.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/28/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

typedef pair<char, int> Bucket;
struct mycomparison{

    bool operator()(const Bucket& b1, const Bucket& b2)const
    {
        return b1.second > b2.second;
    }
} mycomparison;

string rearrangeString(string s, int k) {
    string result = "";
    unordered_map<char, int> numOfEachChar, distanceToGo;
    vector<Bucket> charsRemain;
    int count = 0;
    size_t sizeOfString = s.size();
    for(auto c : s)
    {
        count = max(count, ++numOfEachChar[c]);
    }
    for(auto noec : numOfEachChar)
    {
        charsRemain.push_back(noec);
    }
    int ans = (count - 1) * k;
    for(auto e : numOfEachChar)if(e.second == count)ans++;
    if(ans <= sizeOfString)
    {
        for (int i = 0; i != sizeOfString; ++i) {
            sort(charsRemain.begin(), charsRemain.end(), mycomparison);
            int selected = 0;
            for(int j = 0; j < charsRemain.size(); j++)
            {
                if(distanceToGo[charsRemain[j].first] != 0)
                    distanceToGo[charsRemain[j].first]--;
                if(distanceToGo[charsRemain[j].first] == 0 && charsRemain[j].second > 0 && selected == 0)
                {
                    distanceToGo[charsRemain[j].first] = k;
                    charsRemain[j].second--;
                    result += charsRemain[j].first;
                    selected = 1;
                }
                
            }
            
        }
    }
    return result;
}
