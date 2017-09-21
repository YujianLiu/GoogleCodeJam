//
//  SetZeroes.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

void setZeroes(vector< vector<int> >& matrix) {
    if(matrix.empty())
        return;
    int numOfRow = matrix.size(), numOfCol = matrix[0].size(), col = 1;
    for(int i = 0; i != numOfRow; ++i)
    {
        if(matrix[i][0] == 0) col = 0;
        for(int j = 0; j != numOfCol; ++j)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0;
                
            }
        }
    }
    
    for(int i = numOfRow - 1; i != -1; --i)
    {
        for(int j = numOfCol - 1; j != 0; --j)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if(col == 0) matrix[i][0] = 0;
    }
}
