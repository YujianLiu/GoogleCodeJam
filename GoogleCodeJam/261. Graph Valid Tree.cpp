//
//  261. Graph Valid Tree.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/29/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

bool DFS(vector<int>& mark, int index, int parent, vector<vector<int>>& adjacentList, set<int>& connectionDetection);

bool validTree(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adjacentList(n);
    size_t sizeOfEdges = edges.size();
    for (int i = 0; i < sizeOfEdges; ++i) {
        adjacentList[min(edges[i].first, edges[i].second)].push_back(max(edges[i].first, edges[i].second));
        adjacentList[max(edges[i].first, edges[i].second)].push_back(min(edges[i].first, edges[i].second));
    }
    set<int> connectDetection;
    vector<int> record(n, 0);
    bool result = DFS(record, 0, -1, adjacentList, connectDetection) && connectDetection.size() == n;
    return result;
}

bool DFS(vector<int>& mark, int index, int parent, vector<vector<int>>& adjacentList, set<int>& connectionDetection){
    bool result = true;
    if(mark[index] == 1)
    {
        return false;
    }
    else
    {
        mark[index] = 1;
    }
    connectionDetection.insert(index);
    for(int i = 0; i < adjacentList[index].size(); ++i)
    {
        if(adjacentList[index][i] != parent)
        {
            result = result && DFS(mark, adjacentList[index][i], index, adjacentList, connectionDetection);
        }
    }
    return result;
}
