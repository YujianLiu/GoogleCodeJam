//
//  Add to List 75. Sort Colors.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/4/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


void sortColors(vector<int>& nums) {
    int mid = 0, low = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
        else
        {
            mid++;
        }
    }
}
