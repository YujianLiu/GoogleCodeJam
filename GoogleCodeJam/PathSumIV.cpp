//
//  PathSumIV.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"
int pathSum(vector<int>& nums) {
    int sumOfPath = 0, sizeOfNums = nums.size();
    vector<int> l1(1,-1), l2(2,-1), l3(4,-1), l4(8,-1);
    for(int i = 0; i< sizeOfNums; ++i)
    {
        if(nums[i]/100 == 1)
            l1[0] = nums[i] % 10;
        if(nums[i]/100 == 2)
            l2[nums[i] % 100 / 10] = nums[i] % 10;
        if(nums[i]/100 == 3)
            l3[nums[i] % 100 / 10] = nums[i] % 10;
        if(nums[i]/100 == 4)
            l4[nums[i] % 100 / 10] = nums[i] % 10;
    }
    
    for(int i = 0; i < 1; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            if(l2[j] != -1)
            {
                l2[j] += l1[i];
            }
            
        }
        l1[i] = -1;
            
    }
    
    for(int i = 0; i < 4; ++i)
    {
        if(l3[i] != -1)
        {
            l3[i] += l2[i/2];
        }
    }
    
    for(int i = 0; i < 4; ++i)
    {
        if(l3[i] != -1)
        {
            l2[i/2] = -1;
        }
    }
    
    for(int i = 0; i < 8; ++i)
    {
        if(l4[i] != -1)
        {
            l4[i] += l3[i/2];
        }
    }
    
    for(int i = 0; i < 8; ++i)
    {
        if(l4[i] != -1)
        {
            l3[i/2] = -1;
        }
    }
    for (int i = 0 ; i<l1.size(); i++) {
        if(l1[i]!=-1)
            sumOfPath+=l1[i];
    }
    
    for (int i = 0 ; i<l2.size(); i++) {
        if(l1[i]!=-1)
            sumOfPath+=l2[i];
    }
    
    for (int i = 0 ; i<l3.size(); i++) {
        if(l1[i]!=-1)
            sumOfPath+=l3[i];
    }
    for (int i = 0 ; i<l4.size(); i++) {
        if(l1[i]!=-1)
            sumOfPath+=l4[i];
    }
    return sumOfPath;
}
