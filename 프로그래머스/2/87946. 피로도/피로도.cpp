#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    sort(dungeons.begin(), dungeons.end());
    
    do {
        int remainHP = k;
        int cnt = 0;
        
        for(const vector<int>& dungeon: dungeons) {
            if(remainHP < dungeon[0]) continue;
            remainHP -= dungeon[1];
            cnt++;
        }
        
        answer = max(answer, cnt);
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}