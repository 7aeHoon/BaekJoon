#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> a;
vector<int> path;
vector<bool> used;

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << path[i] << (i + 1 == M ? '\n' : ' ');
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        used[i] = true;
        path.push_back(a[i]);
        dfs(depth + 1);
        path.pop_back();
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    sort(a.begin(), a.end());      // 사전순 출력 보장
    used.assign(N, false);

    dfs(0);
    return 0;
}
