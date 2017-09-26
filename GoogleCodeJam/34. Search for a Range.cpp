//
//  34. Search for a Range.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/4/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//
/*
 Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
 
 Your algorithm's runtime complexity must be in the order of O(log n).
 
 If the target is not found in the array, return [-1, -1].
 
 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
 */
#include "Header.h"


vector<int> searchRange(vector<int>& nums, int target) {
    size_t sizeOfNums = nums.size();
    int left = 0, right_temp = sizeOfNums - 1;
    while (left < right_temp) {
        int mid = (left + right_temp) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else
        {
            right_temp = mid;
        }
    }
    int left_temp = 0, right = sizeOfNums - 1;
    while (left_temp < right) {
        int mid = (left_temp + right + 1) / 2;
        if (nums[mid] > target) {
             right = mid - 1;
        }
        else
        {
            left_temp = mid;
        }
    }
    vector<int> result;
    if(sizeOfNums == 0 or nums[left] != target)
    {
        result.push_back(-1);
        result.push_back(-1);
    }
    else
    {
        result.push_back(left);
        result.push_back(right);
    }
    return result;
}

