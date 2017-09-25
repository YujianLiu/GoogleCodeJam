//
//  128.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/24/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


int longestConsecutive_128(vector<int>& nums) {
    unordered_map<int, int> Connection;
    int result = 0;
    for(auto num : nums){
        Connection[num] = num + 1;
    }
    
    for (auto it = Connection.begin(); it != Connection.end(); it++) {
        
        while (it -> first != it -> second and Connection.find(it -> second) != Connection.end()) {
            int temp = it -> second;
            it -> second = Connection[it -> second];
            Connection[temp] = temp;
        }
        
        result = max(result, it -> second - it -> first);
    }
    return result;
}
