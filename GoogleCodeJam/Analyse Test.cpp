//
//  Analyse Test.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

void merge_Interval(vector<Interval>& intervals, int i, int j){
    Interval    a = intervals[i], b = intervals[j];
    if((a.start <= b.start and a.end >= b.start) or (a.start <= b.end and a.end >= b.end) or (a.start >= b.start and a.end <= b.end)) {
        intervals[j].start = min(a.start, b.start);
        intervals[j].end = max(a.end, b.end);
        intervals.erase(intervals.begin() + i);
    }
}

struct compare{
    bool operator()(const Interval& i1, const Interval& i2)const{
        return i1.start < i2.start;
        }
}MyComp;

vector<Interval> test(vector<Interval>& intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    int Size_Of_Intervals;
    int temp_size;
    
    do{
        int index = 0;
        Size_Of_Intervals = intervals.size();
        temp_size = Size_Of_Intervals;
        
        while(index < Size_Of_Intervals - 1){
            
            merge_Interval(intervals, index, Size_Of_Intervals - 1);
            
            if((temp_size = intervals.size()) != Size_Of_Intervals) break;
            else index++;
            
        }
        
    }while(temp_size != Size_Of_Intervals);
    sort(intervals.begin(), intervals.end(), MyComp);
    
    return intervals;
}

