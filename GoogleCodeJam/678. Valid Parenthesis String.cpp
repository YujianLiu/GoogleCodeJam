//
//  678. Valid Parenthesis String.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/16/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


bool checkValidString(string s) {
    int low = 0;
    int high = 0;
    for (int index = 0 ; index < s.size(); index++) {
        if (s[index] == '(') {
            low++;
            high++;
        }
        else if (s[index] == ')'){
            if (low > 0) {
                low--;
            }
            high--;
        }
        else{
            if (low > 0 ) {
                low--;
            }
            high++;
        }
        if(high < 0)
            return false;
    }
    return low == 0;
}
/*
bool  Rec_Check(int analyse, string s){
    if (analyse == 0 and s.empty()) {
        return true;
    }
    else{
        int index = 0;
        while(index < s.size()){
            if(s[index] == '('){
                analyse++;
            }
            else if(s[index] == ')'){
                if(analyse != 0)
                    analyse--;
                else
                    return false;
            }
            else{
                string temp = "";
                if (index != s.size() - 1) {
                    temp = s.substr(index + 1);
                }
                bool result1 =  Rec_Check(analyse, temp);
                analyse++;
                bool result2 = Rec_Check(analyse, temp);
                analyse--;
                bool result3;
                if (analyse == 0) {
                    result3 = result1;
                }
                else{
                    analyse--;
                    result3 = Rec_Check(analyse, temp);
                }
                return result1 or result2 or result3;
            }
            index++;
        }
        if (analyse == 0) {
            return true;
        }
        else{
            return false;
        }

    }
    
}


bool checkValidString(string s) {
    
    int analyse = 0;
    if (s.empty()) {
        return true;
    }
    else{
        int index = 0;
        while(index < s.size()){
            if(s[index] == '('){
                analyse++;
            }
            else if(s[index] == ')'){
                if(analyse != 0)
                    analyse--;
                else
                    return false;
            }
            else{
                string temp = "";
                if (index != s.size() - 1) {
                    temp = s.substr(index + 1);
                }
                bool result1 =  Rec_Check(analyse, temp);
                analyse++;
                bool result2 = Rec_Check(analyse, temp);
                analyse--;
                bool result3;
                if (analyse == 0) {
                    result3 = result1;
                }
                else{
                    analyse--;
                    result3 = Rec_Check(analyse, temp);
                }
                return result1 or result2 or result3;
            }
            index++;
            cout<<index;
        }
        if (analyse == 0) {
            return true;
        }
        else{
            return false;
        }
    }
    
    
}

*/
