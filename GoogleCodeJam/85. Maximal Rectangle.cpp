//
//  85.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/20/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


int maximalRectangle(vector< vector<char> >& matrix) {
    if(matrix.empty()) return 0;
    int row = matrix.size() , col = matrix[0].size();
    int res=0;
    vector<int> left(col,0),right(col,col),height(row,0);
    for(int i=0;i<row;i++)
    {
        int cur_left=0,cur_right=col;
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]=='1') height[j]++;
            else height[j]=0;
        }
        
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]=='1'){left[j]=max(left[j],cur_left);}
            else {left[j]=0;cur_left=j+1;}
        }
        
        for(int j=col-1;j>=0;j--)
        {
            if(matrix[i][j]=='1'){right[j]=min(right[j],cur_right);}
            else {right[j]=col;cur_right=j;}
        }
        
        for(int j=0;j<col;j++)
        {
            res = max(res,(right[j]-left[j])*height[j]);
        }
        
        
    }
    return res;
}
