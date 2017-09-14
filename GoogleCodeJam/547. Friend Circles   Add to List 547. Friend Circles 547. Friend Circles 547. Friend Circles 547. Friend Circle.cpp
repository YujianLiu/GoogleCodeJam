//
//  Add to List 547. Friend Circles   Add to List 547. Friend Circles 547. Friend Circles 547. Friend Circles 547. Friend Circle.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/30/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


void DFS(vector<bool>& mark, int index, int parent, vector<vector<int>>& M);

int findCircleNum(vector<vector<int>>& M) {
    int numOfStudents = M.size();
    vector<bool> mark(numOfStudents, false);
    int result = 0;
    
    for (int index = 0; index < numOfStudents; ++index) {
        if(mark[index] ==  false)
        {
            DFS(mark, index, -1, M);
            result++;
        }
    }
    
    return result;
}

void DFS(vector<bool>& mark, int index, int parent, vector<vector<int>>& M){
    if(mark[index] == true)
    {
        return;
    }
    else
    {
        mark[index] = true;
    }
    for(int i = 0; i < M.size(); ++i)
    {
        if(i != parent && i != index && M[index][i] == 1)
        {
            DFS(mark, i, index, M);
        }
    }
}
