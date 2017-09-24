//
//  684.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/23/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int Find(unordered_map<int, int>& parent, int val){
    if (parent[val] == 0) {
        return val;
    }
    return Find(parent, parent[val]);
}

void Union(unordered_map<int, int>& parent, int a, int b){
    int xset = Find(parent, a);
    int yset = Find(parent, b);
    
    parent[xset] = yset;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    unordered_map<int, int> parent;
    vector<int> result;
    for(auto edge : edges){
        int a = Find(parent, edge[0]);
        int b = Find(parent, edge[1]);
        
        if (a == b) {
            result = edge;
            break;
        }
        
        Union(parent, a, b);
    }
    return result;
}

