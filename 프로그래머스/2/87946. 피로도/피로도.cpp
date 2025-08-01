#include <bits/stdc++.h>

using namespace std;

bool visited[9];
int result;

// 유저의 현재 피로도, 던전별 최소 필요 피로도와 소모 피로도, 던전 탐험 수
void go(const int &pirodo, const vector<vector<int>> &dungeons, const int &cnt) {
    if (pirodo <= 0) {
        return;
    }

    result = max(result, cnt);
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (pirodo < dungeons[i][0] || visited[i]) { continue; }
        visited[i] = true;
        go(pirodo - dungeons[i][1], dungeons, cnt + 1);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    go(k, dungeons, 0);

    answer = result;

    return answer;
}