//
//  673. Number of Longest Increasing Subsequence.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/9/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int findNumberOfLIS(vector<int>& nums) {
    int NumberOfLIS = 1, Size_Of_LIS = 1, Size_Of_Nums = nums.size();
    if(Size_Of_Nums == 0)
        return 0;
    vector<int> Record_Of_LIS(Size_Of_Nums, 1);
    for (int index = nums.size() - 2; index >= 0 ; index--) {
        for(int search = index; search < nums.size(); search++)
        {
            if(nums[index] < nums[search])
            {
                Record_Of_LIS[index] = max(Record_Of_LIS[search] + 1, Record_Of_LIS[index]);
                if(Record_Of_LIS[index] == Size_Of_LIS)
                    NumberOfLIS++;
                else if(Record_Of_LIS[index] > Size_Of_LIS)
                {
                    Size_Of_LIS = Record_Of_LIS[index];
                    NumberOfLIS = 1;
                }
                
            }
        }
    }
    return NumberOfLIS;
}
/*
 if(nums.empty())
 return 0;
 int NumberOfLIS = 0, Size_Of_LIS = 1, Size_Of_Nums = nums.size();
 vector<int> Record_Of_LIS(Size_Of_Nums, 1);
 
 for (int index = 0; index < nums.size(); index++) {
 for(int refresh = 0; refresh < index; refresh++)
 {
 if(Record_Of_LIS[refresh] < nums[index])
 Record_Of_LIS[refresh]++;
 }
 }
 
 for(int index = 0; index < Size_Of_Nums; index++)
 {
 if (Size_Of_LIS == Record_Of_LIS[index]) {
 NumberOfLIS++;
 }
 else if(Size_Of_LIS < Record_Of_LIS[index])
 {
 Size_Of_LIS = Record_Of_LIS[index];
 NumberOfLIS = 1;
 }
 }
 
 return NumberOfLIS;
 
 */
