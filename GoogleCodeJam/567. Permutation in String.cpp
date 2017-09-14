//
//  Add to List 567. Permutation in String.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/6/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


bool checkInclusion(string s1, string s2) {
    
    unordered_map<char, int> Statistic_Char_S1;
    size_t Size_Of_S1 = s1.size(), Size_Of_S2 = s2.size();
    int index = 0;
    
    if(Size_Of_S1 > Size_Of_S2)
        return false;
    
    for(auto c : s1)
    {
        Statistic_Char_S1[c]++;
    }
    
    unordered_map<char, int> Temp_Table(Statistic_Char_S1);
    int Chars_Remain = (int) Size_Of_S1;
    while (index <= Size_Of_S2 - Size_Of_S1) {
        
        Temp_Table = Statistic_Char_S1;
        Chars_Remain = (int) Size_Of_S1;
        
        for (int Second_index = index; Second_index < Size_Of_S2; ++Second_index) {
            Temp_Table[s2[Second_index]]--;
            
            if(Temp_Table[s2[Second_index]] < 0)
            {
                break;
            }
            else
            {
                Chars_Remain--;
            }
            
            if(Chars_Remain == 0)
                return true;
        }
        
        index++;
    }
    return false;
}
