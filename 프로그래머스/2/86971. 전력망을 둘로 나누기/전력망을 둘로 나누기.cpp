#include <bits/stdc++.h>

using namespace std;

// 트리
vector<vector<int>> tree;
bool visited[101];

int bfs(const int& startNode) {
    int result = 0;
    
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    
    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();
        
        result++;
        
        for(const int& nextNode : tree[currentNode]) {
            if(visited[nextNode]) continue;
            q.push(nextNode);
            visited[nextNode] = true;
            
        }
    }
    
    return result;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    
    tree.resize(n + 1, vector<int>());
    
    // 양쪽 노드에 간선 연결
    for(const vector<int>& wire: wires) {
        tree[wire[0]].push_back(wire[1]);
        tree[wire[1]].push_back(wire[0]);
    }
    
    // 모든 간선을 순회하며 하나씩 간선을 끊어보기
    for(const vector<int>& wire: wires) {
        // 방문 배열 초기화
        memset(visited, false, sizeof(visited));
        // 한쪽을 방문처리해서 방문하지 못하도록
        // 무조건 먼저 방문 처리후 탐색 진행!
        visited[wire[1]] = true;
        int leftNodeCnt = bfs(wire[0]);
        int rightNodeCnt = n - leftNodeCnt;
        
        answer = min(answer, abs(leftNodeCnt - rightNodeCnt));
    }
    
    return answer;
}