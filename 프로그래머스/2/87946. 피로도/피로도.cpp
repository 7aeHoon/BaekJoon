#include <bits/stdc++.h>

using namespace std;

int maxCnt = INT_MIN;

void dfs(const int& remainHP, vector<vector<int>> &dungeons, vector<bool>& visited, const int& cnt) {
    maxCnt = max(maxCnt, cnt);

    for (int i = 0; i < dungeons.size(); i++) {
        if (remainHP < dungeons[i][0] || visited[i]) continue;

        visited[i] = true;
        dfs(remainHP - dungeons[i][1], dungeons, visited, cnt + 1);
        visited[i] = false;
    }
}

// 던전 방문 순서에 따라 결과가 달라짐
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    vector<bool> visited(dungeons.size(), false);

    dfs(k, dungeons, visited, 0);

    answer = maxCnt;

    return answer;
}