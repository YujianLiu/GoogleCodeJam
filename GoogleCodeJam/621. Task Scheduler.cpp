//
//  621. Task Scheduler.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 8/28/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> tasksToDo;
    int count = 0;
    for(auto task : tasks)
    {
        count = max(count, ++tasksToDo[task]);
    }
    int result = (count - 1) * (n + 1);
    for(auto task : tasksToDo){result += task.second == count;}
    return max(result, (int)tasks.size());
}
