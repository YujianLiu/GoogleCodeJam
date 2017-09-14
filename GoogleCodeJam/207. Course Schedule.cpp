//
//  207. Course Schedule.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/29/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

bool DFS(vector<int>& mark, int index, vector<pair<int, int>>& prerequisites);
struct myClass{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){return  p1.first < p2.first;}
} myClass;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    sort(prerequisites.begin(), prerequisites.end(), myClass);
    for(int i = 0; i < numCourses && prerequisites.size() != 0; ++i)
    {
        vector<int> courseTaken(numCourses, 0);
        courseTaken[i] = 1;
        int index = 0;
        while(prerequisites[index].first == i && index != prerequisites.size())
        {
            if(DFS(courseTaken, prerequisites[index].second, prerequisites) == false)return false;
            index++;
        }
        prerequisites.erase(prerequisites.begin(), prerequisites.begin()+index);
        
    }
    return true;
}

bool DFS(vector<int>& mark, int index, vector<pair<int, int>>& prerequisites)
{
    bool result = true;
    if(mark[index] == 1)
        return false;
    else
    {
        mark[index] = 1;
        
        for(auto prerequisite : prerequisites)
        {
            if(prerequisite.first == index)
            {
                result = result && DFS(mark, prerequisite.second, prerequisites);
            }
        }
        mark[index] = 0;
        
    }
    return result;
}
