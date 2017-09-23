//
//  229.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/21/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

vector<int> majorityElement(vector<int>& nums) {
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
    vector<int> result;
    for(auto num : nums){
        if (num == candidate1) {
            count1++;
        } else if(num == candidate2){
            count2++;
        }
        else if (count1 == 0){
            candidate1 = num;
            count1 = 1;
        }else if (count2 == 0){
            candidate2 = num;
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(auto num : nums){
        if (num == candidate1) {
            count1++;
        }
        if (num == candidate2) {
            count2++;
        }
    }
    if (count1 > nums.size() / 3) {
        result.push_back(candidate1);
    }
    if (count2 > nums.size() / 3 and candidate1 != candidate2) {
        result.push_back(candidate2);
    }
    return result;
    
}
