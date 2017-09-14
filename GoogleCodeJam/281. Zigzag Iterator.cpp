//
//  281. Zigzag Iterator.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/7/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        pointers_begin.push_back(v1.begin());
        pointers_begin.push_back(v2.begin());
        pointers_end.push_back(v1.end());
        pointers_end.push_back(v2.end());
        Total_Size += v1.size();
        Total_Size += v2.size();
    }
    
    int next() {
        
        int result = *pointers_begin[pos % pointers_begin.size()];
        pointers_begin[pos % pointers_begin.size()]++;
        return result;
    }
    
    bool hasNext() {
        if(counter == Total_Size)
            return false;
        else
        {
            pos = counter;
            while (pointers_begin[pos % pointers_begin.size()] == pointers_end[pos % pointers_begin.size()]) {
                pos++;
            }
            counter++;
            return true;
        }
    }
private:
    
    int counter = 0, Total_Size = 0, pos = 0;
    vector<vector<int>::iterator> pointers_begin, pointers_end;
};

