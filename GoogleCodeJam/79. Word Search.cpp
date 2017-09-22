//
//  Exist.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

bool recursive(vector< vector<char> >& board, string word, int i, int j)
{
    if(i < 0 || i == board.size() || j < 0 || j == board[0].size())
        return false;
    char record = board[i][j];
    
    
    if(word[0] == board[i][j])
    {
        if(word.size() == 1)
        {
            return true;
        }
        else
        {
            board[i][j] = 0;
            bool result = false;
            for(int offSetX = -1; offSetX != 2; ++offSetX)
                for(int offSetY = -1; offSetY != 2; ++offSetY)
                {
                    if(!(offSetX == offSetY && offSetY == 0) && (offSetY == 0 || offSetX == 0))
                        result = result || recursive(board, word.substr(1), i + offSetX, j + offSetY);
                }
            
            //recursive
            board[i][j] = record;
            return result;
        }
    }
    else
        return false;
    
}

bool exist(vector< vector<char> >& board, string word) {
    if(word.empty())
        return true;
    else if(board.empty())
        return false;
    
    int numOfRow = board.size(), numOfCol = board[0].size();
    bool result = false;
    for(int i = 0; i < numOfRow; i++)
    {
        for(int j = 0; j < numOfCol; j++)
        {
            if(board[i][j] == word[0])
                result  = result || recursive(board, word, i, j);
        }
    }
    
    return result;
}
