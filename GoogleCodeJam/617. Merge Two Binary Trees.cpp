//
//  617.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/24/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 != NULL and t2 != NULL) {
        t1 -> val += t2 -> val;
    }
    if (t1 == NULL and t2 != NULL) {
        return t2;
    }
    if (t1 != NULL and t2 == NULL) {
        return t1;
    }
    if (t1 == NULL and t2 == NULL) {
        return NULL;
    }
    t1 -> left = mergeTrees(t1 -> left, t2 -> left);
    t1 -> right = mergeTrees(t1 -> right, t2 -> right);
    return t1;
}
