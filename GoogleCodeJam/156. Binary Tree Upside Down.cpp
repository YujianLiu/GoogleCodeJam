//
//  156. Binary Tree Upside Down.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/7/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

TreeNode* Recurseive_156(TreeNode* ancestor, TreeNode* root);

TreeNode* upsideDownBinaryTree(TreeNode* root) {
    TreeNode* New_Root = root;
    if (New_Root == NULL) {
        return New_Root;
    }
    
    if (root -> left != NULL) {
        New_Root = Recurseive_156(root, root -> left);
    }
    
    root -> left = NULL;
    root -> right = NULL;
    
    return New_Root;
}

TreeNode* Recurseive_156(TreeNode* ancestor, TreeNode* root){
    TreeNode* New_Root = root;
    
    if(root -> left != NULL){
        New_Root = Recurseive_156(root, root -> left);
    }
    
    root -> right = ancestor;
    root -> left = ancestor -> right;
    
    return New_Root;
}
