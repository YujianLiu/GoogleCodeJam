//
//  MostFrequentSubtreeSum.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

unordered_map<int, int> hashMap;

vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> result;
    
    sumOfSubtree(root);
    
    int frenquecy = 0;
    for(auto it = hashMap.begin(); it != hashMap.end(); ++it)
    {
        frenquecy = max(frenquecy, it->second);
    }
    for(auto it = hashMap.begin(); it != hashMap.end(); ++it)
    {
        if(frenquecy == it -> second)
            result.push_back(it -> first);
    }
    
    return result;
}

int sumOfSubtree(TreeNode* root)
{
    int result = 0;
    if(!root)
        return 0;
    if(root -> left)
        result += sumOfSubtree(root -> left);
    if(root -> right)
        result += sumOfSubtree(root -> right);
    
    hashMap[result += root -> val]++;
    return result;
}
