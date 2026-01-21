#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v, temp;
vector<bool> visited;
vector<vector<int>> result;

void go() {
    if (temp.size() == M) {
        result.push_back(temp);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        temp.push_back(v[i]);
        go();
        temp.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    v.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    go();

    sort(result.begin(), result.end());

    result.erase(unique(result.begin(), result.end()), result.end());

    for (vector<int> v : result) {
        for (int num : v) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}