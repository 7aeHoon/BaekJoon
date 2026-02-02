#include <bits/stdc++.h>

using namespace std;

int N, K, answer;
queue<pair<int, int>> q;
bool visited[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    q.push({N, 0});
    visited[N] = true;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        int x = p.first;
        int cnt = p.second;

        q.pop();

        // 동생하고 같은 위치일 경우
        if (x == K) {
            answer = cnt;
            break;
        }

        // 이동할 수 있는 가능성
        int nx[3] = {x - 1, x + 1, 2 * x};

        for (int i = 0; i < 3; i++) {
            if (nx[i] < 0 || nx[i] > 100000 || visited[nx[i]]) continue;
            visited[nx[i]] = true;
            q.push({nx[i], cnt + 1});
        }
    }

    cout << answer << '\n';

    return 0;
}