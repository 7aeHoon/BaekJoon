#include <bits/stdc++.h>

using namespace std;

int N, M, K, answer;
int arr[51][51];

bool check(int k) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            int num = arr[y][x];
            int ny = y + k - 1;
            int nx = x + k - 1;
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (num != arr[y][nx] || num != arr[ny][x] || num != arr[ny][nx]) continue;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    K = min(N, M);

    for (int len = K; len >= 1; len--) {
        if (check(len)) {
            answer = len;
            break;
        }
    }

    cout << answer * answer << '\n';

    return 0;
}