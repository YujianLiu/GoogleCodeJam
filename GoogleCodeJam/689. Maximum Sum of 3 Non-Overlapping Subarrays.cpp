//
//  689.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 10/1/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    vector<int> result;
    map<int, set<int>> mp;
    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += nums[i];
    }
    mp[sum].insert(0);
    
    for (int i = k; i < nums.size(); i++) {
        sum += nums[i];
        sum -= nums[i - k];
        mp[sum].insert(i - k + 1);
    }
    
    vector<int> List_Of_Index;
    vector<int> Sum_Of_Index(nums.size() - k + 1, 0);
    for (auto it1 = mp.rbegin(); it1 != mp.rend(); ++it1) {
        for (auto it2 = it1 -> second.begin(); it2 != it1 -> second.end(); ++it2) {
            List_Of_Index.push_back(*it2);
            Sum_Of_Index[*it2] = it1 -> first;
        }
    }
    int len = (int)List_Of_Index.size();
    int current_max = 0;
    for (int i = 0; i < len - 2; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            if ((List_Of_Index[i] <= List_Of_Index[j] - k) or (List_Of_Index[i] >= List_Of_Index[j] + k)) {
                for (int l = j + 1; l < len; l++) {
                    if (((List_Of_Index[i] <= List_Of_Index[l] - k) or (List_Of_Index[i] >= List_Of_Index[l] + k)) and ((List_Of_Index[j] <= List_Of_Index[l] - k) or (List_Of_Index[j] >= List_Of_Index[l] + k))){
                        if (Sum_Of_Index[List_Of_Index[i]] + Sum_Of_Index[List_Of_Index[j]] + Sum_Of_Index[List_Of_Index[l]] > current_max) {
                            current_max = Sum_Of_Index[List_Of_Index[i]] + Sum_Of_Index[List_Of_Index[j]] + Sum_Of_Index[List_Of_Index[l]];
                            result.clear();
                            result.push_back(List_Of_Index[i]);
                            result.push_back(List_Of_Index[j]);
                            result.push_back(List_Of_Index[l]);
                            sort(result.begin(), result.end());
                        }
                        break;
                    }
                }
            }
        }
    }
    return result;
}
