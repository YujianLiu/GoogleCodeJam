//
//  222. Count Complete Tree Nodes.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/4/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


int countNodes(TreeNode* root) {
   if(!root)
       return 0;
   else{
       int l = 0, r = 0;
       TreeNode* lr = root, *rr = root;
       while(lr){l++; lr = lr -> left;}
       while(rr){r++; rr = rr -> right;}
       if(l == r) return  pow(2, l) - 1;
       else
           return 1 + countNodes(root -> left) + countNodes(root -> right);
       
   }
}


