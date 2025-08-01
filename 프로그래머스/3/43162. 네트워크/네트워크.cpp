#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> adj(200);
bool visited[200];

void dfs(const int &here) {
    visited[here] = true;
    for (int there: adj[here]) {
        if (!visited[there]) {
            dfs(there);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (computers[i][j] == 1 && i != j) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            answer++;
        }
    }

    return answer;
}
