//
//  220.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/20/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long> window;
    for(int i = 0; i < nums.size(); i++)
    {
        if (i > k) {
            window.erase(nums[i-k-1]);
        }
        
        auto pos = window.lower_bound((long)nums[i]-(long)t);
        if(pos != window.end() && *pos - nums[i] <=  t)  return true;
        window.insert(nums[i]);
    }
    return false;
}
