//
//  45. Jump Game II.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/28/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//
/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 
 Each element in the array represents your maximum jump length at that position.
 
 Your goal is to reach the last index in the minimum number of jumps.
 
 For example:
 Given array A = [2,3,1,1,4]
 
 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 
 Note:
 You can assume that you can always reach the last index.
 
 */

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

