//
//  323. Number of Connected Components in an Undirected Graph.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/30/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

void DFS(vector<int>& mark, int index, int parent, vector<vector<int>>& adjacentList);

int countComponents(int n, vector<pair<int, int>>& edges) {
    vector< vector<int> > adjacentList(n);
    vector<int> mark(n, 0);
    int result = 0;
    for(auto edge : edges)
    {
        int bigger = max(edge.first, edge.second), smaller = min(edge.first, edge.second);
        adjacentList[bigger].push_back(smaller);
        adjacentList[smaller].push_back(bigger);
    }
    for(int index = 0; index < n; ++index)
    {
        if(mark[index] == 0)
        {
            DFS(mark, index, -1, adjacentList);
            result++;
        }
    }
    return result;
}

void DFS(vector<int>& mark, int index, int parent, vector<vector<int>>& adjacentList){
    if (mark[index] == 1) {
        return;
    } else {
        mark[index] = 1;
    }
    for(int i = 0; i != adjacentList[index].size(); ++i)
    {
        if (adjacentList[index][i] != parent) {
            DFS(mark, adjacentList[index][i], index, adjacentList);
        }
    }
}


