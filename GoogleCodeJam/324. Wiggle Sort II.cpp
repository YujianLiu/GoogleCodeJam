//
//  324. Wiggle Sort II.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/4/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


void wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> sortedVector(nums);
    size_t sizeOfNums = nums.size();
    for (int originalIndex = sizeOfNums - 1, biggerIndex = originalIndex / 2 + 1, smallerIndex = 0; originalIndex >= 0; originalIndex--){
        nums[originalIndex] = sortedVector[originalIndex & 1 ? biggerIndex++ : smallerIndex++];
    }
    
}
