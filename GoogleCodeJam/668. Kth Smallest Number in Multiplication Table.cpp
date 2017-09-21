//
//  Kth largest Number in Multiplication Table.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/27/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

/*int findKthNumber(int m, int n, int k) {
    map<int, int> hashMap;
    int result = 0;
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            hashMap[i * j]++;
    int i = 0;
    for(auto it = hashMap.begin(); it != hashMap.end(); ++it)
    {
        i += it -> second;
        if(k <= i)
            return it -> first;
    }
    return 0;
}*/
int findKthNumber(int m, int n, int k)
{
    int low = 1, high = m * n;
    while(low < high)
    {
        int mid = low + (high - low) / 2, cnt = 0;
        for(int i = 1; i <= min(mid, n); ++i)
        {
            cnt += min(mid / i, m);
        }
        if(cnt < k)
        {
            low  = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}



