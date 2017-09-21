//
//  286. Walls and Gates.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/19/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

void wallsAndGates(vector<vector<int>>& rooms) {
    queue<pair<int, int>> CanReach;
    int Num_Of_Row = (int)rooms.size();
    if (Num_Of_Row == 0) {
        return;
    }
    const int Num_Of_Col = (int)rooms[0].size();
    vector<pair<int, int>> steps = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int i = 0; i < Num_Of_Row; i++) {
        for (int j = 0; j < Num_Of_Col; j++) {
            if (rooms[i][j] == 0) {
                CanReach.emplace(i, j);
            }
        }
    }
    
    while (!CanReach.empty()) {
        int x = CanReach.front().first, y = CanReach.front().second;
        CanReach.pop();
        for(auto step : steps){
            int a = x + step.first, b = y + step.second;
            if (a < 0 or b < 0 or a >= Num_Of_Row or b >= Num_Of_Col or rooms[a][b] <= rooms[x][y] + 1) continue;
            rooms[a][b] = rooms[x][y] + 1;
            CanReach.emplace(a,b);
        }
    }
    
}
