//
//  673. Number of Longest Increasing Subsequence.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/9/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

int findNumberOfLIS(vector<int>& nums) {
    
    int Size_Of_Nums = nums.size(), result = 0, longest = 0;
    vector<pair<int ,pair<int, int>>> Table(Size_Of_Nums, {{},{1,1}});
    
    for (int Index = 0; Index < Size_Of_Nums; Index++) {
        
        Table[Index].first = nums[Index];
        int Temp_Length = 0, Temp_Num = 0;
        
        for(int Search_Index = 0; Search_Index < Index; Search_Index++){
            
            if (Table[Search_Index].first < nums[Index]) {
                
                if(Temp_Length == Table[Search_Index].second.first){
                    Temp_Num += Table[Search_Index].second.second;
                }
                else if (Temp_Length < Table[Search_Index].second.first)
                {
                    Temp_Num = Table[Search_Index].second.second;
                }
                Temp_Length = max(Temp_Length, Table[Search_Index].second.first);
                
            }
        }
        
        Table[Index].second.first = Temp_Length + 1;
        Table[Index].second.second = max(Temp_Num, 1);
        
        if(longest < Table[Index].second.first){
            
            longest = Table[Index].second.first;
            result = Table[Index].second.second;
            
        }
        else if (longest == Table[Index].second.first){
            
            result += Table[Index].second.second;
        }
    }
    
    return result;
}
/*
 if(nums.empty())
 return 0;
 int NumberOfLIS = 0, Size_Of_LIS = 1, Size_Of_Nums = nums.size();
 vector<int> Record_Of_LIS(Size_Of_Nums, 1);
 
 for (int index = 0; index < nums.size(); index++) {
 for(int refresh = 0; refresh < index; refresh++)
 {
 if(Record_Of_LIS[refresh] < nums[index])
 Record_Of_LIS[refresh]++;
 }
 }
 
 for(int index = 0; index < Size_Of_Nums; index++)
 {
 if (Size_Of_LIS == Record_Of_LIS[index]) {
 NumberOfLIS++;
 }
 else if(Size_Of_LIS < Record_Of_LIS[index])
 {
 Size_Of_LIS = Record_Of_LIS[index];
 NumberOfLIS = 1;
 }
 }
 
 return NumberOfLIS;
 
 */
