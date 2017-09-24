//
//  683.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/24/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int kEmptySlots(vector<int>& flowers, int k) {
    int Slot_Len = (int)flowers.size();
    map<int, vector<int>> flower_Bloomed;
    for (int index = 0; index < Slot_Len; index++) {
        flower_Bloomed[flowers[index]].push_back(INT_MAX);
        flower_Bloomed[flowers[index]].push_back(INT_MAX);
        auto it = flower_Bloomed.find(flowers[index]);
        if (it != flower_Bloomed.begin()) {
            auto it2 = it;
            it2--;
            it -> second[0] = min(it -> second[0], abs(it2 -> first - it -> first));
            it2 -> second[1] = min(it2 ->second[1], it -> second[0]);
        }
        auto it2 = it;
        it2++;
        if (it2 != flower_Bloomed.end()) {
            it -> second[1] = min(it -> second[1], abs(it2 -> first - it -> first));
            it2 -> second[0] = min(it2 -> second[0], it -> second[1]);
        }
        if (it -> second[0] == k + 1 or it -> second[1] == k + 1) {
            return index + 1;
        }
    }
    
    return -1;
}
