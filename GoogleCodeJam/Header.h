//
//  Header.h
//  GoogleCodeJam
//
//  Created by yujian liu on 8/26/17.
//  Copyright © 2017 yujian liu. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <deque>
#include <stack>
#include <sstream>

using namespace std;  // since cin and cout are both in namespace std, this saves some text


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
         int start;
         int end;
         Interval() : start(0), end(0) {}
         Interval(int s, int e) : start(s), end(e) {}
     };

bool recursive2(vector< vector<char> >& board, string word, int i, int j);
vector<string> findWords(vector< vector<char> >& board, vector<string>& words);


//bool recursive(vector< vector<char> >& board, string word, int i, int j);
//bool exist(vector< vector<char> >& board, string word);


//double findMaxAverage(vector<int>& nums, int k);
//void setZeroes(vector< vector<int> >& matrix);

//void gameOfLife(vector< vector<int> >& board);

//vector<string> findRepeatedDnaSequences(string s);

int countUnivalSubtrees(TreeNode* root);
bool isUnivalSubtree(TreeNode* root);

bool isSubtree(TreeNode* s, TreeNode* t);
bool match(TreeNode* s, TreeNode* t);

vector<int> findFrequentTreeSum(TreeNode* root);
int sumOfSubtree(TreeNode* root);
string minWindow(string s, string t);

bool checkPossibility(vector<int>& nums);

int pathSum(vector<int>& nums);
int findKthNumber(int m, int n, int k);

vector<int> constructArray(int n, int k);

int leastInterval(vector<char>& tasks, int n);

string rearrangeString(string s, int k);

int canCompleteCircuit(vector<int>& gas, vector<int>& cost);

int jump(vector<int>& nums);
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
bool validTree(int n, vector<pair<int, int>>& edges);
int countComponents(int n, vector<pair<int, int>>& edges);
int findCircleNum(vector<vector<int>>& M);

int longestValidParentheses(string s);

vector<int> searchRange(vector<int>& nums, int target);
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval);

int minSubArrayLen(int s, vector<int>& nums);
bool checkInclusion(string s1, string s2);
int lengthOfLongestSubstringTwoDistinct(string s);
bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs);

class WordDistance {
public:
    WordDistance(vector<string> words) {
        
        for(auto word : words){
            if (Word_Index.find(word) == Word_Index.end()) {
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
};

#endif /* Header_h */
