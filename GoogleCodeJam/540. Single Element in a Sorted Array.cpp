//
//  3.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/20/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int singleNonDuplicate(vector<int>& nums)
{
    int l = 0, r = nums.size()-1, mid = (l + r) / 2;
    while (l < r)
    {
        if (nums[mid] == nums[mid + 1])
        {
            if ((mid - 1) % 2 == 0)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 2;
            }
        }
        else if (nums[mid] == nums[mid - 1])
        {
            if ((mid - 1) % 2 ==0)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 2;
            }
        }
        else
        {
            return nums[mid];
        }
        mid = (l + r) / 2;
        
    }
    return nums[l];
    
}

