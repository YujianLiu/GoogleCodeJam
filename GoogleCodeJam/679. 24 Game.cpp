//
//  679. 24 Game.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/16/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

double calc(int opera, double a, double b)
{
    switch (opera) {
        case 0:
            return (a + b);
            break;
        case 1:
            return (a - b);
            break;
        case 2:
            return (a * b);
            break;
        default:
            if (b != 0) {
                return  a/b;
            }
            else{
                return 36 * 37;
            }
            
            break;
    }
}

bool judgePoint24(vector<int>& nums) {
    vector<vector<double>> Orders_Of_Nums;
    vector<vector<int>> Orders_Of_Operators;
    vector<vector<int>> Orders_Of_parentheses;
    
    for (int i = 0; i < nums.size(); i++) {
        unordered_map<int, int> mark;
        
        mark[i] = 1;
        for(int j = 0; j < nums.size(); j++){
            if (mark[j] != 1){
                mark[j] = 1;
                for(int k = 0; k < nums.size(); k++){
                    if(mark[k] != 1){
                        mark[k] = 1;
                        for(int l = 0; l < nums.size(); l++){
                            if (mark[l] != 1) {
                                vector<double> Order_Of_Nums;
                                Order_Of_Nums.push_back(nums[i]);
                                Order_Of_Nums.push_back(nums[j]);
                                Order_Of_Nums.push_back(nums[k]);
                                Order_Of_Nums.push_back(nums[l]);
                                Orders_Of_Nums.push_back(Order_Of_Nums);
                            }
                        }
                        mark[k] = 0;
                    }
                }
                mark[j] = 0;
            }
        }
        mark[i] = 0;
        
    }
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                vector<int> Order_Of_Operators;
                Order_Of_Operators.push_back(i);
                Order_Of_Operators.push_back(j);
                Order_Of_Operators.push_back(k);
                Orders_Of_Operators.push_back(Order_Of_Operators);
            }
        }
    }
    
    for (int i = 0; i < 3; ++i) {
        unordered_map<int, int> mark;
        mark[i] = 1;
        for (int j = 0; j < 3; ++j) {
            if (mark[j] != 1) {
                mark[j] = 1;
                for (int k = 0; k < 3; ++k) {
                    if (mark[k] != 1) {
                        vector<int> Order_Of_Parentheses;
                        Order_Of_Parentheses.push_back(i);
                        Order_Of_Parentheses.push_back(j);
                        Order_Of_Parentheses.push_back(k);
                        Orders_Of_parentheses.push_back(Order_Of_Parentheses);
                    }
                }
                mark[j] = 0;
            }
            
        }
    }
    
    for(auto order_of_nums : Orders_Of_Nums){
        
        for(auto order_of_parentheses : Orders_Of_parentheses){
            
            for(auto order_of_operators : Orders_Of_Operators){
                auto Temp_order_of_nums = order_of_nums;
                auto Temp_order_of_parentheses = order_of_parentheses;
                auto Temp_order_of_operators = order_of_operators;
                
                while (Temp_order_of_nums.size() > 1) {
                    
                    Temp_order_of_nums[Temp_order_of_parentheses[0]] = calc(Temp_order_of_operators[Temp_order_of_parentheses[0]], Temp_order_of_nums[Temp_order_of_parentheses[0]], Temp_order_of_nums[Temp_order_of_parentheses[0] + 1]);
                    if (Temp_order_of_nums[Temp_order_of_parentheses[0]] == 36 * 37) {
                        break;
                    }
                    Temp_order_of_nums.erase(Temp_order_of_nums.begin() + Temp_order_of_parentheses[0] + 1);
                    Temp_order_of_operators.erase(Temp_order_of_operators.begin() + Temp_order_of_parentheses[0]);
                    for(auto& pos : Temp_order_of_parentheses){
                        if (pos > Temp_order_of_parentheses[0]) {
                            pos--;
                        }
                    }
                    Temp_order_of_parentheses.erase(Temp_order_of_parentheses.begin());
                }
                if (abs(Temp_order_of_nums[0] - 24) < 0.4) {
                    return true;
                }
                if (Temp_order_of_nums[0] == 24) {
                    return true;
                }
                
            }
        }
    }
    
        return false;
}
