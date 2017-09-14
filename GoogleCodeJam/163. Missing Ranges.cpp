//
//  163. Missing Ranges.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/7/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

string get_Range(int start, int end){
    return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
}


vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> result;
    long pre = (long) lower - 1;
    
    for (int index = 0; index <= nums.size(); ++index) {
        long cur = (index == nums.size() ? (long) upper + 1 : (long) nums[index]);
        if(cur - pre >= 2)
            result.push_back(get_Range(pre + 1, cur - 1));
        pre = cur;
    }
    
    return result;
    
}
