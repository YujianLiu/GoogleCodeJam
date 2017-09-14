//
//  354. Russian Doll Envelopes.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/4/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

struct mycompare{
    bool operator()(const pair<int, int>& e1, const pair<int, int>& e2)const{
        if(e1.first == e2.first)
            return e1.second < e2.second;
        else
            return e1.first < e2.first;
    }
}myComp;


int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), myComp);
    size_t sizeOfEnvelopes = envelopes.size();
    vector<int> dp(sizeOfEnvelopes, 1);
    int result = 0;
    
    for(int i = 0; i < sizeOfEnvelopes; ++i){
        for (int j = 0; j < i; ++j) {
            if(envelopes[i].first > envelopes[j].first and envelopes[i].second > envelopes[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        result = max(result, dp[i]);
    }
    
    return result;
    
}
