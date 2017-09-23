//
//  306.cpp
//  GoogleCodeJam
//
//  Created by liuyujian on 9/22/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"
string Sum_String(string a, string b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    
    for (int index = 0; index < b.size(); index++) {
        int bitsum = (carry + a[index] - '0' + b[index] - '0') % 10;
        carry = (carry + a[index] - '0' + b[index] - '0') / 10;
        a[index] = bitsum + '0';
    }
    
    if (carry == 1) {
        int index = (int)b.size();
        while(index < a.size() and carry == 1){
            int bitsum = (carry + a[index] - '0') % 10;
            carry = (carry + a[index] - '0') / 10;
            a[index] = bitsum + '0';
            index++;
        }
        if (carry == 1) {
            a += '1';
        }
    }
    
    reverse(a.begin(), a.end());
    return a;
}

string Make_Sum(string s, int a, int b){
    string sum_a = s.substr(0, a + 1), sum_b = s.substr(a + 1, b - a);
    if (sum_a.size() > sum_b.size()) {
        return  Sum_String(sum_a, sum_b);
    }else{
        return  Sum_String(sum_b, sum_a);
    }
    
}

bool Check_Next(string sum_a, string sum_b, string rest){
    string New_Sum = sum_a.size() > sum_b.size() ? Sum_String(sum_a, sum_b) : Sum_String(sum_b, sum_a);
    if(rest.size() < New_Sum.size()) return false;
    else{
        if(rest.substr(0, New_Sum.size()) == New_Sum)
            return Check_Next(sum_b, New_Sum, rest.substr(New_Sum.size()));
    }
    return false;
}

bool isAdditiveNumber(string num) {
    for(int index = 0; index < num.size()/2; index++)
        for (int next_index = index + 1; next_index + index < num.size()/2 ; next_index++) {
            if (num[0] != '0' and num[index + 1] != '0') {
                string sum = Make_Sum(num, index, next_index);
                int Sum_Size = (int)sum.size();
                if (sum == num.substr(next_index + 1, Sum_Size)) {
                    return Check_Next(num.substr(index, next_index - index), sum, num.substr(next_index));
                }
            }
        }
    return false;
}
