//
//  254. Factor Combinations.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/18/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

vector<vector<int>> getFactors(int n) {
    vector<vector<int>> result;

    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            result.push_back({n / i, i});
            vector<vector<int>> temp_results = getFactors(n / i);
            for(auto temp_result : temp_results){
                if (temp_result.back() >= i) {
                    temp_result.push_back(i);
                    result.push_back(temp_result);
                }
            }
            
        }
    }
    return result;
}
