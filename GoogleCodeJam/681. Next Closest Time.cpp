//
//  681.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/23/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int calcdiff(string a, string b){
    if (b < a) {
        return 24 * 60 - calcdiff(b, a);
    }
    int hour1 = stoi(a.substr(0, 2)), hour2 = stoi(b.substr(0, 2));
    int minute1 = stoi(a.substr(3, 2)), minute2 = stoi(b.substr(3, 2));
    int hourdiff = 0;
    if (hour2 < hour1) {
        hourdiff = hour2 + 24 - hour1;
    } else {
        hourdiff = hour2 - hour1;
    }
    return hourdiff * 60 + minute2 - minute1;
}

string nextClosestTime(string time) {
    set<char> Char_List;
    for (int index= 0; index < time.size(); index++) {
        if (time[index] >= '0' and time[index] <= '9') {
            Char_List.insert(time[index]);
        }
    }
    set<string> string_list;
    
    for(auto it1 = Char_List.begin(); it1 != Char_List.end(); it1++){
        for (auto it2 = Char_List.begin(); it2 != Char_List.end(); it2++) {
            string hour;
            hour += *it1;
            hour += *it2;
            if (hour < "24") {
                for(auto it3 = Char_List.begin(); it3 != Char_List.end(); it3++){
                    for (auto it4 = Char_List.begin(); it4 != Char_List.end(); it4++) {
                        string minute;
                        minute += *it3;
                        minute += *it4;
                        if (minute < "60") {
                            string_list.insert(hour + ':' + minute);
                        }
                    }
                }
            }
        }
    }
    auto it = string_list.find(time);
    auto it1 = it, it2 = it, it3 = it;
    if(string_list.size() == 1){
        return *it;
    }
    if (it == string_list.begin()) {
        it2 = string_list.end()--;
        it3++;
    } else if(++it == string_list.end()){
        it2 = string_list.begin();
        it3--;
    }else{
        it2--;
        it3++;
    }
    return calcdiff(*it1, *it2) < calcdiff(*it1, *it3) ? *it2 : *it3;
    
}
