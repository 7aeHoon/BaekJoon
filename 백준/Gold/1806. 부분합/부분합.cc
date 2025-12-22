#include <bits/stdc++.h>

using namespace std;

int answer = 987654321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // 연속된 수들의 부분 합
    int sum = 0;
    // 시작 포인터
    int start = 0;

    for (int end = 0; end < N; end++) {
        sum += v[end];

        while (sum >= S) {
            answer = min(answer, end - start + 1);
            sum -= v[start];
            start++;
        }

        if(end < start) break;
    }

    // 합을 만들 수 없었을 경우
    if (answer == 987654321) answer = 0;

    cout << answer << '\n';

    return 0;
}
