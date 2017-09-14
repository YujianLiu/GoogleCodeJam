//
//  469. Convex Polygon.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/9/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

long D(const vector<vector<int>>& A);

bool isConvex(vector<vector<int>>& points) {
    int pos= 0, neg = 0, Size_Of_Points = points.size();
    for (int Index = 0; Index < Size_Of_Points; ++Index) {
        long del = D({points[Index], points[(Index + 1) % Size_Of_Points], points[(Index + 2) % Size_Of_Points]});
        if((pos |= (del > 0)) * (neg |= (del < 0))) return false;
    }
    return true;
}

long D(const vector<vector<int>>& A){
    return (A[1][0]-A[0][0]) * (A[2][1] - A[0][1]) - (A[1][1] - A[0][1]) * (A[2][0] - A[0][0]);
}


