//
//  674. Longest Continuous Increasing Subsequence.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/9/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int findLengthOfLCIS(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int result = 1, start = 0, index = 0;
    for (; index < nums.size(); ++index) {
        if(index != (nums.size() - 1) && nums[index] >= nums[index + 1])
        {
            result = max(result, index - start + 1);
            start = index + 1;
        }
        else if(index == nums.size() - 1)
        {
            result = max(result, index - start + 1);
        }
    }
    
    return result;
}
