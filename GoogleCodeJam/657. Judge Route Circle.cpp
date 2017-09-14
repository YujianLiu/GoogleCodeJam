//
//  657. Judge Route Circle.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/30/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


bool judgeCircle(string moves) {
    map<char,int> moveCount;
    for(char move : moves)
    {
        moveCount[move]++;
    }
    if(moveCount['U'] == moveCount['D'] && moveCount['L'] == moveCount['R'])
        return true;
    else
        return false;
}
