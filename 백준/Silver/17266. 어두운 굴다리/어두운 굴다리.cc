#include <bits/stdc++.h>

using namespace std;

int N, M, answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> M;

    vector<int> v(M);

    for (int i = 0; i < M; i++) {
        cin >> v[i];
    }

    // 가로등은 최소 1개이상 설치됨

    answer = max(v.front(), N - v.back());

    for (int i = 1; i < M; i++) {
        int dist = (v[i] - v[i - 1] + 1) / 2;
        answer = max(answer, dist);
    }

    cout << answer << '\n';

    return 0;
}
