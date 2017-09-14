//
//  296. Best Meeting Point.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/6/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int minTotalDistance(vector<vector<int>>& grid) {
    size_t Num_Of_Row = grid.size(), Num_Of_Col;
    int result = 0;
    
    if (Num_Of_Row != 0) {
        Num_Of_Col = grid[0].size();
    }
    else
        return 0;
    
    vector<int> Coordinates_X, Coordinates_Y;

    int Meet_X, Meet_Y;
    
    for(int Row = 0; Row < Num_Of_Row; ++Row)
        for(int Col = 0; Col < Num_Of_Col; ++Col)
        {
            if(grid[Row][Col] == 1)
            {
                Coordinates_X.push_back(Row);
                Coordinates_Y.push_back(Col);
            }
        }
    sort(Coordinates_Y.begin(), Coordinates_Y.end());
    Meet_X = Coordinates_X[Coordinates_X.size() / 2];
    Meet_Y = Coordinates_Y[Coordinates_Y.size() / 2];
    
    for(int Row = 0; Row < Num_Of_Row; ++Row)
        for(int Col = 0; Col < Num_Of_Col; ++Col)
            if( grid[Row][Col] == 1)
                result += abs(Row - Meet_X) + abs(Col - Meet_Y);

    return result;
}
