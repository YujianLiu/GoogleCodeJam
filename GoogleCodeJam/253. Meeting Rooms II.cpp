//
//  253. Meeting Rooms II.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/6/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int minMeetingRooms(vector<Interval>& intervals) {
    vector<int> Starting_Times, Ending_Times;
    int result = 0;
    
    for(auto interval : intervals)
    {
        Starting_Times.push_back(interval.start);
        Ending_Times.push_back(interval.end);
    }
    sort(Starting_Times.begin(), Starting_Times.end());
    sort(Ending_Times.begin(), Ending_Times.end());
    
    int i = 0, j = 0;
    while (i < Starting_Times.size()) {
        if(Starting_Times[i] < Ending_Times[j])
            i++;
        else
            j++;
        result = max(result, i - j);
    }
    
    
    return result;
}
