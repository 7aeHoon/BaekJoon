#include <bits/stdc++.h>

using namespace std;

int N, M, K, X;
bool visited[300005];
vector<int> city[300005];
vector<int> cities;
queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        city[from].push_back(to);
    }

    q.push({X, 0});
    visited[X] = true;

    while (!q.empty()) {
        int currentCity = q.front().first;
        int dist = q.front().second;
        q.pop();

        // 출발 도시로부터 K만큼 초과할 경우 종료
        if (dist > K) break;

        // 출발 도시로부터 거리가 K인 도시를 저장
        if (dist == K) {
            cities.push_back(currentCity);
        }

        // 거리 1의 인접한 도시
        for (const int nextCity : city[currentCity]) {
            // 방문한 도시일 경우 패스
            if (visited[nextCity]) continue;
            q.push({nextCity, dist + 1});
            visited[nextCity] = true;
        }
    }

    if (!cities.empty()) {
        sort(cities.begin(), cities.end());

        for (int city : cities) {
            cout << city << '\n';
        }
    } else {
        cout << -1 << '\n';
    }

    return 0;
}