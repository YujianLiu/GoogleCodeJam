//
//  164.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/24/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    
    for(auto num : nums){
        minimum = min(minimum, num);
        maximum = max(maximum, num);
    }
    
    int gap = (maximum - minimum - 2) / (nums.size() - 1) + 1;
    vector<int> bucketMin(nums.size() - 1, INT_MAX);
    vector<int> bucketMax(nums.size() - 1, INT_MIN);
    
    for(auto num : nums){
        int idx = (num - minimum) / gap;
        if (num == minimum or num == maximum) {
            continue;
        }
        
        bucketMax[idx] = max(bucketMax[idx], num);
        bucketMin[idx] = min(bucketMin[idx], num);
        
    }
    
    int prev = minimum;
    int result = INT_MIN;
    for (int index = 0; index < nums.size() - 1; index++) {
        if (bucketMin[index] == INT_MAX and bucketMax[index] == INT_MIN) {
            continue;
        }
        result = max(result, bucketMin[index] - prev);
        prev = bucketMax[index];
    }
    result = max(result, maximum - prev);
    
    return result;
    
}
