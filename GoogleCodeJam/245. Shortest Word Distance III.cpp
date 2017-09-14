//
//  245. Shortest Word Distance III.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/9/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int w1p = -1, w2p = -1, SW_Distance = INT_MAX;
    
    if(word1 != word2)
        for(int index = 0; index < words.size(); index++){
        
        if(words[index] == word1)
        {
            w1p = index;
            if(w2p != -1)
            {
                SW_Distance = min(SW_Distance, abs(w1p - w2p));
            }
        }
        
        if (words[index] == word2) {
            w2p = index;
            if(w1p != -1)
            {
                SW_Distance = min(SW_Distance, abs(w1p - w2p));
            }
        }
    }
    else
        for (int index = 0; index < words.size(); index++) {
            if (words[index] == word1) {
                if(w1p != -1)
                {
                    SW_Distance = min(SW_Distance, index - w1p);
                }
            
                w1p = index;
            }
        }
    return SW_Distance;
}
