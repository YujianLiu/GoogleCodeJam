//
//  IsSubtree.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


bool isSubtree(TreeNode* s, TreeNode* t) {
    bool result = match(s, t);
    if(result == true )
        return result;
    if(s -> left)
        result = result || isSubtree(s -> left, t);
    if(s -> right)
        result = result || isSubtree(s -> right, t);
    return result;
}

bool match(TreeNode* s, TreeNode* t)
{
    bool result = false;
    if(s == NULL && t == NULL)
        result = true;
    else if (s == NULL)
        result = false;
    else if (t == NULL)
        result = false;
    else
        result = (s -> val == t -> val) && match(s -> left, t -> left) && match(s -> right, t -> right);
    return result;
}
