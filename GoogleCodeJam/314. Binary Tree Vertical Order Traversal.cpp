//
//  314.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/20/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

map<int, vector<int>> hash_map;
queue<pair<TreeNode*, int>> q;
void BFS_314(TreeNode* root){
    int level = 0;
    if (root) {
        q.push({root, level});
    }
    while (!q.empty()) {
        auto current = q.front();
        hash_map[current.second].push_back(current.first -> val);
        if (current.first -> left) {
            q.push({current.first -> left, current.second - 1});
        }
        if (current.first -> right) {
            q.push({current.first -> right, current.second + 1});
        }
        q.pop();
    }
}

vector<vector<int>> verticalOrder(TreeNode* root) {
    BFS_314(root);
    vector<vector<int>> result;
    for (auto it = hash_map.begin(); it != hash_map.end(); ++it) {
        result.push_back(it -> second);
    }
    return result;
}
