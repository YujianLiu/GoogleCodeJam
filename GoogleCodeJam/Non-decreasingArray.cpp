//
//  Non-decreasingArray.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"
bool checkPossibility(vector<int>& nums) {
    
    int sizeOfNums = nums.size(), count = 0;
    for(int i = 0; i < sizeOfNums - 1; ++i)
    {
        if(nums[i] > nums[i + 1])
        {
            if(i == 0)
                nums[i] = nums[i + 1];
            else if(nums[i + 1] >= nums[i - 1])
            {
                nums[i] = nums[i - 1];
            }
            else
            {
                nums[i + 1] = nums[i];
            }
            count++;
        }
        
        if(count == 2)
            return false;
        
    }
    
    return true;
}
