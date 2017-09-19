//
//  285. Inorder Successor in BST.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/19/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    vector<TreeNode*> Inoreder_Traverse;
    stack<TreeNode*> Dfs;
    
    TreeNode* current = root;
    bool done = false;
    while (!done) {
        if (current != NULL) {
            Dfs.push(current);
            current = current -> left;
        } else {
            if (!Dfs.empty()) {
                current = Dfs.top();
                Inoreder_Traverse.push_back(current);
                Dfs.pop();
                current = current -> right;
            } else {
                done = true;
            }
        }
    
    }
    for (int i = 0; i < Inoreder_Traverse.size(); i++) {
        if (Inoreder_Traverse[i] == p and i != Inoreder_Traverse.size() - 1) {
            return Inoreder_Traverse[i + 1];
        }
    }
    
    return NULL;
}
