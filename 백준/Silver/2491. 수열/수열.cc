#include <bits/stdc++.h>

using namespace std;

int N, upCnt = 1, downCnt = 1, answer = 1;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 1; i < N; i++) {
        if (v[i - 1] > v[i]) {
            upCnt++;
            downCnt = 1;
        } else if (v[i - 1] < v[i]) {
            downCnt++;
            upCnt = 1;
        } else {
            upCnt++;
            downCnt++;
        }
        answer = max(answer, upCnt);
        answer = max(answer, downCnt);
    }

    cout << answer << '\n';

    return 0;
}