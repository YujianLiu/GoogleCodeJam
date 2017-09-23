//
//  120.cpp
//  GoogleCodeJam
//
//  Created by liuyujian on 9/22/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

struct SimpleHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return p.first xor p.second;
    }
};

unordered_map<pair<int, int>, int, SimpleHash> hash_map_120;

int Recursive_120(vector<vector<int>>& triangle, int level, int pos){
    if (hash_map_120.find({level, pos}) != hash_map_120.end()) {
        return hash_map_120[{level, pos}];
    } else if (level == triangle.size() - 1) {
        hash_map_120[{level, pos}] = triangle[level][pos];
        return triangle[level][pos];
    }
    else{
        hash_map_120[{level, pos}] = triangle[level][pos] + min(Recursive_120(triangle, level + 1, pos), Recursive_120(triangle, level + 1, pos + 1));
        return hash_map_120[{level, pos}];
    }
}

int minimumTotal(vector<vector<int>>& triangle) {
    if (!triangle.empty()) {
        return Recursive_120(triangle, 0, 0);
    } else {
        return 0;
    }
    
}
