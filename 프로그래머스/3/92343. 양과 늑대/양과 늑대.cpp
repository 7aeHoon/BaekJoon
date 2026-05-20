#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int maxSheep;

void dfs(int node, int sheep, int wolf, const vector<int>& info, const vector<vector<int>>& edges) {
    // 현재 위치에 양이 있을 경우
    if(info[node] == 0) {
        sheep++;
    } 
    // 현재 위치에 늑대가 있을 경우
    else {
        wolf++;
    }

    //     // 일단 최대 양 갱신
    // maxSheep = max(maxSheep, sheep);

    // 늑대의 수가 양의 수 이상일 경우
    if(sheep <= wolf) return;

    maxSheep = max(maxSheep, sheep);

    // 모든 간선 탐색 진행
    for(int i = 0; i < edges.size(); i++) {
        // 부모 노드 번호
        int parent = edges[i][0];
        int child = edges[i][1];
        // 현재 노드가 부모 노드인 간선만 체크
        // if(node == parent) {
            // edge[i]번 간선 가능
            if(visited[parent] && !visited[child]) {
                visited[child] = true;
                dfs(child, sheep, wolf, info, edges);
                visited[child] = false;
            }
        // }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    // 전체 노드의 수
    int n = info.size();

    tree.resize(n);
    visited.resize(n, false);

    // 간선을 연결하여 트리 형태로 만들기
    for(const vector<int>& edge: edges) {
        tree[edge[0]].push_back(edge[1]);
    }

    visited[0] = true;

    // 0번 노드에서 일단 시작
    dfs(0, 0, 0, info, edges);


    return maxSheep;
}