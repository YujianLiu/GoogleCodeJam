//
//  BeautifulArrangement2.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


vector<int> constructArray(int n, int k) {
    vector<int> result;
    for(int i = 0; i < n; i++)
    {
        result.push_back(i+1);
    }
    int i = 1;
    while (k > 0) {
        if( i % 2 == 1)
            result[i] = result[i - 1] + k;
        else
            result[i] = result[i - 1] - k;
        k--;
        i++;
    }
    return result;
}
