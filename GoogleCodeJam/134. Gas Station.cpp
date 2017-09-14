//
//  134. Gas Station.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/28/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = -1;
    size_t sizeOfCircle = gas.size();
    for(int i = 0; i < sizeOfCircle; i++)
    {
        int totalGas = gas[i], totalCost = cost[i];
        for(int j = i + 1; j != i; j++ )
        {
            if(j == sizeOfCircle)
            {
                j = 0;
                if(j == i)
                    break;
            }
            if(totalGas < totalCost)
                break;
            totalGas += gas[j];
            totalCost += cost[j];
        }
        if(totalCost <= totalGas)
            return i;
        
    }
    return start;
}
