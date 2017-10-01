//
//  687.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/30/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int result = 0;
queue<TreeNode*> q_687;

int helper_687(TreeNode* root, int current_depth){
    
    int left_depth = 0, right_depth = 0;
    
    if(root){
        if (root -> left ) {
            if (root -> left -> val == root -> val) {
                left_depth = helper_687(root -> left, current_depth + 1);
            }
            else
            {
                q_687.push(root -> left);
                
            }
            
        }
        if (root -> right) {
            if (root -> right -> val == root -> val) {
                right_depth = helper_687(root -> right, current_depth + 1);
            }
            else
            {
                q_687.push(root -> right);
                
            }
        }
        
        if(root == q_687.front()) return left_depth + right_depth;
        else if(left_depth == 0 and right_depth == 0) return current_depth;
        else return max(left_depth, right_depth);
    }
    
    return 0;
}

int longestUnivaluePath(TreeNode* root) {
    q_687.push(root);
    while (!q_687.empty()) {
        result = max(result, helper_687(q_687.front(), 0));
        q_687.pop();
    }
    
    return result;
}
