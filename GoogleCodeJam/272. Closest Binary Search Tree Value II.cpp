//
//  272. Closest Binary Search Tree Value II.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/2/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


void preOrderTraversal(vector<int>& record, TreeNode* root)
{
    if(root != NULL)
    {
        preOrderTraversal(record, root -> left);
        record.push_back(root -> val);
        preOrderTraversal(record, root -> right);
    }
}

vector<int> closestKValues(TreeNode* root, double target, int k) {
    vector<int> record;
    preOrderTraversal(record, root);
    size_t sizeOfRecord = record.size();
    for (int i = 0; i < sizeOfRecord - k; i++) {
        if(abs(target - (double)record.front()) > abs(target - (double)record.back()))
            record.erase(record.begin());
        else
            record.erase(record.end() - 1);
    }
    return record;
    
}
