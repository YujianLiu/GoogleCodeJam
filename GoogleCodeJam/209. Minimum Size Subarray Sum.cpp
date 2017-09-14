//
//  209. Minimum Size Subarray Sum.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/5/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


int minSubArrayLen(int s, vector<int>& nums) {
    
    size_t sizeOfNums = nums.size();
    vector<int> subCandidate(sizeOfNums, -1);
    int sumOfSub = 0, sizeOfScope = 0;
    int result = INT_MAX;
    
    for (int index = 0; index < sizeOfNums; ++index) {
        
        sumOfSub += nums[index];
        sizeOfScope++;
        
        while (sizeOfScope >= 0 && sumOfSub >= s) {
            subCandidate[index] = sizeOfScope;
            if(sumOfSub - nums[index - sizeOfScope + 1] >= s)
            {
                sumOfSub -= nums[index - sizeOfScope + 1];
                sizeOfScope--;
                
            }
            else
                break;
            
        }
        
    }
    
    for (auto candidate : subCandidate) {
        if(candidate > 0)
        result = min(result, candidate);
    }
    if(result == INT_MAX)
        result = 0;
    
    return result;
}
