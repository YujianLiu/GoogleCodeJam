//
//  279.cpp
//  GoogleCodeJam
//
//  Created by liuyujian on 9/22/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

unordered_map<int, int> hash_map_279;

int numSquares(int n) {
    if (hash_map_279.find(n) != hash_map_279.end()) {
        return hash_map_279[n];
    }
    int result = INT_MAX;
    
    if (n == 0) {
        hash_map_279[0] = 0;
        return 0;
    } else {
        
        for (int i = floor(sqrt(n)); i >= 1 ; i--) {
            int temp = 1 + numSquares(n - i*i);
            result = min(temp,result);
        }
        hash_map_279[n] = result;
        return result;
    }
    
}
