//
//  WordSearch2.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

bool recursive2(vector< vector<char> >& board, string word, int i, int j)
{
    if(i < 0 || i == board.size() || j < 0 || j == board[0].size())
        return false;
    char record = board[i][j];
    
    if(word[0] == record)
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
                    if(!(offSetX == offSetY && offSetY == 0) && (offSetY == 0 || offSetX == 0)){
                        
                        result = result || recursive2(board, word.substr(1), i + offSetX, j + offSetY);
                    }
                    
                }
            
            //recursive
            board[i][j] = record;
            return result;
        }
    }
    else
        return false;
}

vector<string> findWords(vector< vector<char> >& board, vector<string>& words) {
    size_t sizeOfWords = words.size(), numOfRow = board.size(), numOfCol = board[0].size();
    vector<string> result;
    unordered_map<string, int> hashOfString;
    for(int i = 0; i != numOfRow; ++i)
    {
        for(int j = 0; j != numOfCol; ++j)
        {
            for(int k = 0; k < sizeOfWords; ++k)
            {
                if(hashOfString[words[k]] != 1 )
                {
                        if(recursive2(board, words[k], i, j))
                        {
                            result.push_back(words[k]);
                            hashOfString[words[k]] = 1;
                        }
                }
                
            }
        }
    }
    
    return result;
}
