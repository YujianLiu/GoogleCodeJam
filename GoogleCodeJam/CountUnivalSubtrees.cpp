//
//  CountUnivalSubtrees.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"



int countUnivalSubtrees(TreeNode* root) {
    int cntUS = 0;
    if(root == NULL)
        return 0;
    if(root -> left == NULL && root -> right == NULL)
    {
        cntUS++;
    }
    else if(root -> left == NULL)
    {
        cntUS = countUnivalSubtrees(root -> right);
        if(root -> val == root -> right -> val && isUnivalSubtree(root -> right))
            cntUS++;
    }
    else if (root -> right == NULL)
    {
        cntUS = countUnivalSubtrees(root -> left);
        if(root -> val == root -> left -> val && isUnivalSubtree(root -> left))
            cntUS++;
    }
    else
    {
        cntUS = countUnivalSubtrees(root -> left) + countUnivalSubtrees(root -> right);
        if(root -> val == root -> left -> val && root -> val == root -> right -> val && isUnivalSubtree(root -> left) && isUnivalSubtree(root ->right))
            cntUS++;
    }
    
    return cntUS;
}

bool isUnivalSubtree(TreeNode* root)
{
    bool result = false;
    if(root -> left == NULL && root -> right == NULL)
        result = true;
    else if(root -> left == NULL)
    {
        if(root -> val == root -> right -> val && isUnivalSubtree(root -> right))
            result = true;
    }
    else if (root -> right == NULL)
    {
        if(root -> val == root -> left -> val && isUnivalSubtree(root -> left))
            result = true;
    }
    else
    {
        if(root -> val == root -> left -> val && root -> val == root -> right -> val && isUnivalSubtree(root -> right) && isUnivalSubtree(root -> left))
            result = true;
    }
    
    return result;
    
}





