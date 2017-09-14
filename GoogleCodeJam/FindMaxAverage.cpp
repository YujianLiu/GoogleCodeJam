//
//  FindMaxAverage.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

double findMaxAverage(vector<int>& nums, int k) {
    long sum = 0;
    int i = 0, n = nums.size();
    while (i < k) {
        sum += nums[i++];
    }
    while (i < n)
    {
        sum = max(sum, sum + nums[i] - nums[i - k]);
        i++;
    }
    return (double) sum / k;
}
