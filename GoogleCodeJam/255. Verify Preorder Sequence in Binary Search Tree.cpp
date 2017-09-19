//
//  255. Verify Preorder Sequence in Binary Search Tree.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/18/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

bool verifyPreorder(vector<int>& preorder) {
    int low = INT_MIN;
    stack<int> Ancestor;
    for(auto p : preorder){
        if (low > p) {
            return false;
        }
        while (!Ancestor.empty() and Ancestor.top() < p) {
            low = Ancestor.top();
            Ancestor.pop();
        }
        
        Ancestor.push(p);
    }
    return true;
}
