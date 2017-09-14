//
//  444. Sequence Reconstruction.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 9/8/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#include "Header.h"


// Learn To use string org, another solution

bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    if(seqs.size() == 0) return false;
    int Org_Size = org.size(), count = 0;
    unordered_map<int, unordered_set<int>> graph;
    vector<int> outdegree(Org_Size + 1, 0);
    
    for(auto seq : seqs)
        for(int Index = seq.size() - 1; Index >= 0; --Index){
            if(seq[Index] > Org_Size or seq[Index] < 1) return false;
            if(Index > 0 and graph[seq[Index]].count(seq[Index - 1]) == 0){
                graph[seq[Index]].insert(seq[Index - 1]);
                if(outdegree[seq[Index - 1]]++ == 0) count++;
            }
            if(Index == 0 and graph.find(seq[Index]) == graph.end()){
                graph.insert({seq[Index], unordered_set<int> ()});
            }
        }
    
    if(count != Org_Size - 1) return false;
    if(graph.size() != Org_Size) return false;
    for(int index = Org_Size - 1; index >= 0; --index){
        if(outdegree[org[index]] != 0) return false;
        for(auto parent : graph[org[index]]){
            if(--outdegree[parent] == 0 and parent != org[index - 1])return false;
        }
    }
    return true;
}
