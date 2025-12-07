#include <bits/stdc++.h>

using namespace std;

int answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    vector<bool> visited(20001);

    for (int i = 0; i < N; i++) {
        // 햄버거를 만났을 경우
        if (str[i] == 'H') continue;
        // 시작 지점
        int start = max(0, i - K);
        // 끝 지점
        int end = min(N - 1, i + K);
        // 먹을 수 있는 햄버거 탐색
        for (int j = start; j <= end; j++) {
            if (str[j] == 'P' || visited[j]) continue;
            // 먹었다고 표시
            visited[j] = true;
            answer++;
            break;
        }
    }

    cout << answer << '\n';

    return 0;
}
