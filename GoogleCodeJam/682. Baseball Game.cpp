//
//  682.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/23/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int calPoints(vector<string>& ops) {
    size_t Num_Of_Ops = ops.size();
    vector<int> Points_Each_Round;
    int sum = 0;
    
    for (int index = 0; index < Num_Of_Ops; index++) {
        if (ops[index] == "+") {
             Points_Each_Round.push_back(Points_Each_Round.back() + Points_Each_Round[Points_Each_Round.size() - 2]);
            sum += Points_Each_Round.back();
        }else if (ops[index] == "D"){
            Points_Each_Round.push_back(2 * Points_Each_Round.back());
            sum += Points_Each_Round.back();
        }else if (ops[index] == "C"){
            sum -= Points_Each_Round.back();
            Points_Each_Round.pop_back();
        }else{
            Points_Each_Round.push_back(stoi(ops[index]));
            sum += Points_Each_Round.back();
        }
    }
    return sum;
}
