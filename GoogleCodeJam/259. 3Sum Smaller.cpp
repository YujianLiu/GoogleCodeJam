//
//  Add to List 259. 3Sum Smaller.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/19/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int threeSumSmaller(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int count = 0, len = nums.size();
    for (int index = 0; index < len - 2; index++) {
        int left = index + 1, right = len - 1;
        while (left < right) {
            if (nums[index] + nums[left] + nums[right] < target) {
                count += right - left;
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return count;
}
