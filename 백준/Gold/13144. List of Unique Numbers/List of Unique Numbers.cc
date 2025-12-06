#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<bool> visited(100001, false);

    long long answer = 0;

    int l = 0;

    for (int r = 0; r < N; r++) {
        while (visited[v[r]]) {
            visited[v[l]] = false;
            l++;
        }

        visited[v[r]] = true;

        answer += (r - l + 1);
    }

    cout << answer << '\n';

    return 0;
}
