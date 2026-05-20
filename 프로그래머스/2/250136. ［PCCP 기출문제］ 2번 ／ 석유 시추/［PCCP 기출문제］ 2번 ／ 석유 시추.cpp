#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs(int y, int x, int groupId, const vector<vector<int>>& land, vector<vector<int>>& visited) {
    int result = 0;
    int n = land.size();
    int m = land[0].size();
    queue<pair<int, int>> q;
    
    q.push({y, x});
    visited[y][x] = groupId;
    
    while(!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        result++;
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(land[ny][nx] == 0 ||visited[ny][nx] != 0) continue;
            
            q.push({ny ,nx});
            visited[ny][nx] = groupId;
        }
    }
    
    return result;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    // 가로 및 세로 사이즈
    int n = land.size();
    int m = land[0].size();
    
    // 그룹(방문) 처리 벡터

    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    // 각 그룹에서 발견된 석유
    unordered_map<int, int> oil;
    
    // 그룹 아이디
    // 그룹은 1번부터 시작
    int id = 1;
    
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            // 그룹 부여가 되지 않은 석유 덩어리
            if(land[y][x] == 1 && visited[y][x] == 0) {
                // 해당 그룹에서 뽑은 석유 사이즈
                int oilSize = bfs(y, x, id, land, visited);
                // 그룹 : 추출한 석유 크기
                oil[id] = oilSize;
                id++;
            }
        }
    }
    
    for(int x = 0; x < m; x++) {
        int totalOil = 0;
        
        unordered_set<int> usedGroupId;
        
        for(int y = 0; y < n; y++) {
            int groupId = visited[y][x];
            if(groupId == 0) continue;
            if(usedGroupId.count(groupId)) continue;
            usedGroupId.insert(groupId);
            totalOil += oil[groupId];
        }
        
        answer = max(answer, totalOil);
    }
    
    return answer;
}