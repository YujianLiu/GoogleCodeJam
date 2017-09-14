//
//  251. Flatten 2D Vector.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/6/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


//Another way: using iterator "begin" "end" "pointer of each vectors";

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        Num_Of_Row = (int) vec2d.size();
        if(Num_Of_Row != 0)
            for(auto vec : vec2d)
                for(auto element : vec)
                    Flat_2D.push_back(element);
    }
    
    int next() {
        return Flat_2D[Current_Position++];
    }
    
    bool hasNext() {
        if (Current_Position < (int) Flat_2D.size()) {
            return true;
        }
        else
            return false;
    }
private:
    int Num_Of_Row = 0;
    int Current_Position = 0;
    vector<int> Flat_2D;
};
