//
//  57. Insert Interval.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/4/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//
/*
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 
 You may assume that the intervals were initially sorted according to their start times.
 
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 
 
 
 
 */
#include "Header.h"


struct mycompare{
    bool operator()(const Interval& i1, const Interval& i2)const{
        return i1.start < i2.start;
    }
}myComp2;
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    int mergeFlag = 1;
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
