#include <bits/stdc++.h>

using namespace std;

int N, M, K, X;
int visited[300005];
bool found;
vector<int> city[300005];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        city[from].push_back(to);
    }

    memset(visited, -1, sizeof(visited));

    q.push(X);
    visited[X] = 0;

    while (!q.empty()) {
        // 현재 도시
        int currentCity = q.front();
        q.pop();

        for (int nextCity : city[currentCity]) {
            // 이미 방문한 도시인 경우
            if (visited[nextCity] != -1) continue;
            // 다음 도시
            q.push(nextCity);
            // 방문 도시 처리
            visited[nextCity] = visited[currentCity] + 1;
        }
    }

    for (int i = 0; i <= N; i++) {
        if (visited[i] == K) {
            cout << i << '\n';
            found = true;
        }
    }

    if (!found) {
        cout << -1 << '\n';
    }

    return 0;
}