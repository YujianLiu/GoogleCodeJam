//
//  439. Ternary Expression Parser.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/8/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

string parseTernary(string expression) {
    size_t index = 0;
    while ((index = expression.find_last_of("?")) != string::npos) {
        if (expression[index - 1] == 'T') {
            expression[index - 1] = expression[index + 1];
            expression.erase(index, 4);
        }
        else{
            expression[index - 1] = expression[index + 3];
            expression.erase(index, 4);
        }
    }
    return expression;
}
