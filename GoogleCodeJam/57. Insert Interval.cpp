//
//  57. Insert Interval.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/4/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


struct mycompare{
    bool operator()(const Interval& i1, const Interval& i2)const{
        return i1.start < i2.start;
    }
}myComp2;
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    int mergeFlag = 1, numOfIntervals = intervals.size();
    vector<Interval> result;
    unordered_map<int, int> intervalsToRemove;
    while (mergeFlag) {
        mergeFlag = 0;
        
        for (int i = 0; i < intervals.size(); ++i) {
            if (!(intervals[i].start > newInterval.end || intervals[i].end < newInterval.start) && intervalsToRemove[i] == 0) {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
                intervalsToRemove[i] = 1;
                mergeFlag = 1;
            }
        }
    }
    
    for(int i = 0; i < intervals.size(); i++)
    {
        if (intervalsToRemove[i] != 1) {
            result.push_back(intervals[i]);
        }
    }
    result.push_back(newInterval);
    sort(result.begin(), result.end(), myComp2);
    return result;
}
