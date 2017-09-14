//
//  311. Sparse Matrix Multiplication.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/6/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int Num_Of_New_Row = (int) A.size(), Num_Of_New_Col = (int) B[0].size();
    vector<int> New_Row(Num_Of_New_Col, 0);
    vector<vector<int>> result(Num_Of_New_Row, New_Row);
    unordered_map<int, vector<pair<int, int>>> Left_Matrix, Right_Matrix;
    
    for(int Row = 0; Row < A.size(); ++Row)
        for(int Col = 0; Col < A[0].size(); ++Col)
            if(A[Row][Col] != 0){
                Left_Matrix[Col].push_back(make_pair(Row, A[Row][Col]));
            }
    
    for(int Row = 0; Row < B.size(); ++Row)
        for(int Col = 0; Col < B[0].size(); ++Col)
            if(B[Row][Col] != 0){
                Right_Matrix[Row].push_back(make_pair(Col, B[Row][Col]));
            }
    
    for(auto it = Left_Matrix.begin(); it != Left_Matrix.end(); ++it)
    {
        if (Right_Matrix.find(it -> first) != Right_Matrix.end()) {
            
            vector<pair<int, int>> Left_Temp = it -> second, Right_Temp = Right_Matrix[it -> first];
            
            for (int index = 0; index < Left_Temp.size(); ++index) {
                for(int index_2 = 0; index_2 < Right_Temp.size(); ++index_2)
                    result[Left_Temp[index].first][Right_Temp[index_2].first] += Left_Temp[index].second * Right_Temp[index_2].second;
            }
        }
    }
    
    return result;
}
