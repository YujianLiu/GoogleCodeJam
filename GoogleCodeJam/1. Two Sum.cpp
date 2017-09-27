//
//  1.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/27/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//
/*
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 Example:
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 */

#include "Header.h"

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> diff_idx;
    vector<int> result;
    for (int index = 0; index < nums.size(); index++) {
        if (diff_idx.find(nums[index]) == diff_idx.end()) {
            diff_idx[target - nums[index]] = index;
        }
        else
        {
            result.push_back(diff_idx[nums[index]]);
            result.push_back(index);
        }
    }
    return result;
}
