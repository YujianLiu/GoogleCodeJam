//
//  688.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/30/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

vector<vector<vector<double>>> m2;


double knightProbability(int N, int K, int r, int c) {
    if(m2.empty()){
        for (int k = 0; k < K; k++) {
            vector<vector<double>> m3;
            for(int i = 0; i < N; i++){
                vector<double> m1;
                for(int j = 0; j < N; j++)
                {
                    m1.push_back(0);
                }
                m3.push_back(m1);
            }
            m2.push_back(m3);
        }
        
        
    }
    double result = 0,pos = 0.125;
    if (r >= 0 and r < N and c >= 0 and c < N) {
        if (K == 0) {
            return 1;
        }
        if (m2[K - 1][r][c] != 0) {
            return m2[K - 1][r][c];
        }
        int r1 = r - 1, r2 = r - 2, r3 = r + 1, r4 = r + 2;
        int c1 = c - 1, c2 = c - 2, c3 = c + 1, c4 = c + 2;
        result = pos*(knightProbability(N, K - 1, r1, c2) + knightProbability(N, K - 1, r1, c4) + knightProbability(N, K - 1, r2, c1) + knightProbability(N, K-1, r2, c3) + knightProbability(N, K - 1, r3, c2) + knightProbability(N, K - 1, r3, c4) + knightProbability(N, K - 1, r4, c1) + knightProbability(N, K - 1, r4, c3));
        
        m2[K - 1][r][c] = result;
        
        
    }
    
    return result;
}
