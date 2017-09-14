//
//  GameOfLife.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

void gameOfLife(vector< vector<int> >& board) {
    
    int m = board.size(), n = board[0].size();
    if(board.size()==0)
        return;
    
    vector< vector<int> > newBoard;
    
    
    
    for(int i = 0; i != m; ++i)
    {
        vector<int> newRow;
        for(int j = 0; j != n; ++j)
        {
            int numOfLives = 0;
            for(int offSideX = -1; offSideX != 2; ++offSideX)
                for(int offSideY = -1; offSideY !=2; ++offSideY)
                    if(i + offSideX >= 0 && i + offSideX < m && j + offSideY >= 0 && j + offSideY < n)
                        if(!(offSideX == offSideY && offSideY == 0))
                            if(board[i + offSideX][j + offSideY] == 1)
                            {
                                numOfLives++;
                            }
            
            
            if(board[i][j] == 1)
            {
                if(numOfLives < 2 || numOfLives > 3)
                    newRow.push_back(0);
                if(numOfLives >= 2 && numOfLives <= 3)
                    newRow.push_back(1);
            }
            else
            {
                if(numOfLives == 3)
                    newRow.push_back(1);
                else
                    newRow.push_back(0);
            }
            
        }
        newBoard.push_back(newRow);
    }
    
    board = newBoard;
}
