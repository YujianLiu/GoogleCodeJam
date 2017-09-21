//
//  298.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/20/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

vector<vector<int>> recursive_298(TreeNode* root){
    vector<vector<int>> Result_Candidates;
    
    if (root) {
        if (root -> left) {
            auto temp = recursive_298(root -> left);
            for(auto row : temp){
                Result_Candidates.push_back(row);
            }
        }
        if (root -> right) {
            auto temp = recursive_298(root -> right);
            for(auto row : temp){
                Result_Candidates.push_back(row);
            }
        }
        for(auto& candidate : Result_Candidates){
            candidate.push_back(root -> val);
        }
        if (!root -> left and !root -> right) {
            Result_Candidates.push_back({root -> val});
        }
    }
    
    return Result_Candidates;
}

int longestConsecutive(TreeNode* root) {
    vector<vector<int>> Result_Candidates;
    if (root) {
        if (root -> left) {
            auto temp = recursive_298(root -> left);
            for(auto row : temp){
                Result_Candidates.push_back(row);
            }
        }
        if(root -> right){
            auto temp = recursive_298(root -> right);
            for(auto row : temp){
                Result_Candidates.push_back(row);
            }
        }
        for(auto& candidate : Result_Candidates){
            candidate.push_back(root -> val);
        }
        if (!root -> left and !root -> right) {
            Result_Candidates.push_back({root -> val});
        }
    }
    int result = 0;
    for(auto candidate : Result_Candidates){
        int temp_result = 1, increas = 1, len = candidate.size();
        int flag = 0;
        for (int i = 0; i < len - 1; i++) {
           if (candidate[i] == candidate[i + 1] + 1){
                if (flag == 0) {
                    increas = 2;
                }
                else{
                    increas++;
                }
                flag = 1;
            }else{
                flag = 0;
                increas = 1;
            }
            temp_result = max(temp_result, increas);
        }
        result = max(result, temp_result);
    }
    
    return result;
}


/*
 int rec(TreeNode* root, TreeNode* parent, int len){
     if(!root) return len;
      len = (parent and root -> val == parent -> val + 1) ? len + 1 : 1;
     return max(len, max(rec(root -> left, root, len), rec(root -> right, root, len)));
 }
 
 int longestConsecutive(TreeNode* root) {
 return rec(root, nullptr, 0);
 }
 
 
 */
