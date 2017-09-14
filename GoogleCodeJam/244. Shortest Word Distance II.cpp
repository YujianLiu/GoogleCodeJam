//
//  244. Shortest Word Distance II.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/7/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"

/*class WordDistance {
public:
    WordDistance(vector<string> words) {
        
        for(auto word : words){
            if (Word_Index.find(word) != Word_Index.end()) {
                Word_Index[word] = count++;
            }
        }
        
        vector<int> t(count, INT_MAX);
        vector<vector<int>> temp(count, t);
        Distance_Map = temp;
        
        int Index = 0;
        while (Index < words.size()) {
            for (int Search_Index = 0; Search_Index < Index; Search_Index++) {
                int distance = Distance_Map[Word_Index[words[Search_Index]]][Word_Index[words[Index]]];
                Distance_Map[Word_Index[words[Search_Index]]][Word_Index[words[Index]]] = min(Index - Search_Index, distance);
                Distance_Map[Word_Index[words[Index]]][Word_Index[words[Search_Index]]] = min(Index - Search_Index, distance);
                Distance_Map[Word_Index[words[Search_Index]]][Word_Index[words[Search_Index]]] = 0;
                Distance_Map[Word_Index[words[Index]]][Word_Index[words[Index]]] = 0;
            }
            Index++;
        }
        
    }
    
    int shortest(string word1, string word2) {
        return Distance_Map[Word_Index[word1]][Word_Index[word2]];
    }
    int count = 0;
    unordered_map<string, int> Word_Index;
    vector<vector<int>> Distance_Map;
};*/


/*
 class WordDistance {
 public:
 WordDistance(vector<string>& words) {
 for(int i=0;i<words.size();i++)
 wordMap[words[i]].push_back(i);
 }
 int shortest(string word1, string word2) {
 int  i=0, j=0, dist = INT_MAX;
 while(i < wordMap[word1].size() && j <wordMap[word2].size()) {
 dist = min(dist, abs(wordMap[word1][i] - wordMap[word2][j]));
 wordMap[word1][i]<wordMap[word2][j]?i++:j++;
 }
 return dist;
 }
 private:
 unordered_map<string, vector<int>> wordMap;
 };
 
 */
