#include <bits/stdc++.h>

using namespace std;

int N, answer;
vector<int> v, temp;
vector<bool> visited;

int sum() {
    int result = 0;

    for (int i = 1; i < N; i++) {
        result += abs(temp[i - 1] - temp[i]);
    }

    return result;
}

void go() {
    if (temp.size() == N) {
        answer = max(answer, sum());
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

    cin >> N;

    v.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    go();

    cout << answer << '\n';

    return 0;
}