//
//  161. One Edit Distance.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/7/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

bool isOneEditDistance(string s, string t) {
    
    size_t Size_Of_S = s.size(), Size_Of_T = t.size();
    if(Size_Of_S > Size_Of_T) return isOneEditDistance(t, s);
    else if (Size_Of_T - Size_Of_S > 1) return false;
    bool mismatch = false;
    for (int i = 0; i < Size_Of_S; ++i) {
        if (s[i] != t[i]) {
            if (Size_Of_S == Size_Of_T) {
                s[i] = t[i];
            }
            else{
                s.insert(i, 1, t[i]);
            }
            mismatch = true;
            break;
        }
    }
    return (!mismatch && Size_Of_T - Size_Of_S == 1) || (mismatch && s == t);
}

/*
int Size_Of_S = (int) s.size(), Size_Of_T = (int) t.size();
vector<int> row(Size_Of_S + 1, 0);
vector<vector<int>> dp(Size_Of_T + 1, row);

for (int i = 0; i <= Size_Of_T; ++i) {
    for(int j = 0; j <= Size_Of_S; ++j)
        if(i == 0)
        {
            dp[i][j] = j;
        }
        else if(j == 0)
        {
            dp[i][j] = i;
        }
        else{
            if(s[j-1] == t[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
                else{
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
        }
}
if(dp[Size_Of_T][Size_Of_S] == 1)
return true;
else
return false;*/
