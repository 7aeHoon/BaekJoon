#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    // 튜플 수
    int n = relation.size();
    // 컬럼 수
    int m = relation[0].size();
    
    // 후보키 등록 벡터
    vector<int> candidateKeys;
    
    for(int mask = 1; mask < (1 << m); mask++) {
        // 최소성 만족 여부
        bool isMinimal = true;
        
        for(const int& key: candidateKeys) {
            // 기존 key의 부분집합일 경우
            if((mask & key) == key) {
                isMinimal = false;
                break;
            }
        }
        
        // 최소성을 만족하지 않는 컬럼 조합일 경우
        if(!isMinimal) continue;
        
        set<string> s;
        
        for(int row = 0; row < n; row++) {
            string tuple = "";
            
            for(int col = 0; col < m; col++) {
                if(mask & (1 << col)) {
                    tuple += relation[row][col] + ',';
                }
            }
            
            s.insert(tuple);
        }
        
        if(s.size() == n) {
            candidateKeys.push_back(mask);
        }
    }
    
    answer = candidateKeys.size();
    
    return answer;
}