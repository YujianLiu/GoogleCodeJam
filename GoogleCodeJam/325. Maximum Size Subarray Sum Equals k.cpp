//
//  325. Maximum Size Subarray Sum Equals k.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/6/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


int maxSubArrayLen(vector<int>& nums, int k) {
    
    unordered_map<int, int> Sums_Untill;
    int result = 0, Size_Of_Array = (int) nums.size(), Current_Sum = 0;
    
    for (int index = 0; index < Size_Of_Array; ++index) {
        
        Current_Sum += nums[index];
        
        if(Current_Sum == k)
        {
            result = max(result, index + 1);
        }
        else if(Sums_Untill.find(Current_Sum - k) != Sums_Untill.end())
        {
            result = max(result, index - Sums_Untill[Current_Sum - k]);
        }
        
        if(Sums_Untill.find(Current_Sum) == Sums_Untill.end())
            Sums_Untill[Current_Sum] = index;
    }
    
    return result;
}
