//
//  675. Cut Off Trees for Golf Event.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/10/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

struct compare{
    
    bool operator()(const pair<int, pair<int, int>>& t1, const pair<int, pair<int, int>>& t2){
        
        return t1.first < t2.first;
    }
    
}Compare_675;

int Find_Dis(vector<vector<int>>& forest, vector<vector<int>>& Land_Scape, pair<int, int> start){
    
    if (Land_Scape[start.first][start.second] == -1) {
        return 0;
    }
    queue<pair<int, int>> Flood;
    Flood.push(start);
    
    while (!Flood.empty()) {
        int X = Flood.front().first, Y = Flood.front().second;
        for (int OffSet_X = -1; OffSet_X < 2; OffSet_X++) {
            for (int OffSet_Y = -1; OffSet_Y < 2; OffSet_Y++) {
                if (OffSet_X + X >= 0 and OffSet_Y + Y >= 0 and OffSet_X + X < Land_Scape.size() and OffSet_Y + Y < Land_Scape[OffSet_X + X].size() and !(OffSet_X == OffSet_Y) and !(OffSet_X == -OffSet_Y) ) {
                    if (Land_Scape[X + OffSet_X][Y + OffSet_Y] == 0) {
                        Land_Scape[X + OffSet_X][Y + OffSet_Y] = Land_Scape[X][Y] + 1;
                        Flood.push({X + OffSet_X, Y + OffSet_Y});
                    }
                    else if(Land_Scape[X + OffSet_X][Y + OffSet_Y] == -1){
                        return Land_Scape[X][Y] + 1;
                    }
                }
            }
        }
        Flood.pop();
    }
    return -1;
}

int cutOffTree(vector<vector<int>>& forest) {
    
    int result = 0, Pos_Row = 0, Pos_Col = 0;
    vector<pair<int, pair<int, int>>> TreePos;
   
    for(int Row = 0; Row < forest.size(); Row++)
        for (int Col = 0; Col < forest[Row].size(); Col++) {
            if(forest[Row][Col] > 1)
                TreePos.push_back({forest[Row][Col],{Row, Col}});
        }
    sort(TreePos.begin(), TreePos.end(), Compare_675);
    
    pair<int, int> start{0,0};
    for(auto tree : TreePos){
        
        vector<vector<int>> Land_Scape;
       
        
        for (int Row_Index = 0; Row_Index < forest.size(); Row_Index++) {
            vector<int> Row;
            for (int Col_Index = 0; Col_Index < forest[Row_Index].size(); Col_Index++) {
                if(forest[Row_Index][Col_Index] == 0){
                    Row.push_back(2500);
                }
                else{
                    Row.push_back(0);
                }
            }
            Land_Scape.push_back(Row);
        }
        
        Pos_Row = tree.second.first;
        Pos_Col = tree.second.second;
        Land_Scape[Pos_Row][Pos_Col] = -1;
        
        int distance;
        
        distance = Find_Dis(forest, Land_Scape, start);
        start = tree.second;
        forest[Pos_Row][Pos_Col] = 1;
        if(distance == -1)
            return -1;
        else
            result += distance;
    
    }
    
    return result;
}
