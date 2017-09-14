//
//  45. Jump Game II.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/28/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"



/*int jump(vector<int>& nums) {
    size_t numOfNum = nums.size();
    vector<int> cache(numOfNum, 0);
    int i = numOfNum - 2;
    while (i >= 0) {
        int minsetp = INT_MAX;
        if(nums[i] + i + 1 >= numOfNum)
            cache[i] = 1;
        else{
            for(int j = 0; j <= nums[i]; j++)
            {
                if(j == 0)
                    minsetp = INT_MAX;
                else
                    minsetp = min(minsetp, 1 + min(INT_MAX - 1,cache[min(i + j, (int)(numOfNum - 1))]));
            }
            cache[i] = minsetp;
        }
        
        i--;
    }
        return cache[0];
}*/
int jump(vector<int>& nums)
{
    size_t numOfNum = nums.size();
    int result = 0, maxReach = 0, hold = 0;
    while (maxReach < numOfNum - 1) {
        result++;
        int temp = hold;
        maxReach = temp + nums[temp];
        int forecast = maxReach;
        for(int i = maxReach; i > temp; i--)
        {
            
            if (forecast < i + nums[i]) {
                forecast = i + nums[i];
                hold = i;
            }
        }
        
    }
  
    return result;
    
}

