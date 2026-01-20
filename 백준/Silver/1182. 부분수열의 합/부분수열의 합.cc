#include <bits/stdc++.h>

using namespace std;

int N, S, answer;
int a[21];

void go(int index, int sum) {
    if (index == N) {
        if (sum == S) answer++;
        return;
    }

    go(index + 1, sum + a[index]);
    go(index + 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    go(0, 0);

    if (S == 0) answer--;

    cout << answer << '\n';

    return 0;
}