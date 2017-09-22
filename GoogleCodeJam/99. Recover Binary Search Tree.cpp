//
//  99.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/21/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


 pair<TreeNode*, TreeNode*> Recursive_99(TreeNode* root){
     pair<TreeNode*, TreeNode*> result, final_result{root, root};
     bool needChange = true;
     while (needChange) {
         needChange = false;
            if(root){
                if (root -> left) {
                    result = Recursive_99(root -> left);
                    if (result.second -> val > root -> val) {
                        swap(result.second -> val, root -> val);
                        needChange = true;
                    }
                    final_result.first = result.first -> val < result.second -> val ? result.first : result.second;
                }
                if (root -> right) {
                    result = Recursive_99(root -> right);
                    if (result.first -> val < root -> val) {
                        swap(result.first -> val, root -> val);
                        needChange = true;
                    }
                    final_result.second = result.first -> val > result.second -> val ? result.first : result.second;
                }
            }
     }
     return final_result;
}

void recoverTree(TreeNode* root) {
    pair<TreeNode*, TreeNode*> result{NULL,NULL};
    bool needChange = true;
    while (needChange) {
        needChange = false;
        if (root) {
            if (root -> left) {
                result.first = Recursive_99(root -> left).second;
                if (result.first -> val > root -> val) {
                    swap(result.first -> val, root -> val);
                    needChange = true;
                }
            }
            if (root -> right) {
                result.second = Recursive_99(root -> right).first;
                if (result.second -> val < root -> val) {
                    swap(result.second -> val, root -> val);
                    needChange = true;
                }
            }
        }
    }
    
}






