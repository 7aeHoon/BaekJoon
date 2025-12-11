#include <bits/stdc++.h>

using namespace std;

int answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) {
        int position;
        cin >> position;

        v[i].first = position - 0.5;
        v[i].second = position + 0.5;
    }

    sort(v.begin(), v.end());

    // 테이프
    int tapeStart = 0;
    int tapeEnd = 0;

    for (int i = 0; i < N; i++) {
        int nextStart = v[i].first, nextEnd = v[i].second;

        if (tapeEnd < nextStart) {
            tapeStart = nextStart;
            tapeEnd = nextStart;
        }

        // 커버 가능할 수 있도록 테이프를 계속 붙임
        while (tapeEnd < nextEnd) {
            tapeEnd += L;
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}
