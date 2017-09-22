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
        }else if (count2 == 0){
            candidate2 = num;
        }
        else{
            count1--;
            count2--;
        }
    }
    
    
}
