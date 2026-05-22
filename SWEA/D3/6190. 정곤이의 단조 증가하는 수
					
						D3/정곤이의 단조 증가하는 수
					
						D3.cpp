#include <bits/stdc++.h>

using namespace std;

bool check(const int& num) {
    string str = to_string(num);
    char current = str[0];

    for (int i = 1; i < str.size(); i++) {
        if (current > str[i]) return false;
        current = str[i];
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++) {
        int N;
        cin >> N;

        // 단조 증가 수 중 최댒값
        int answer = -1;

        vector<int> nums(N);

        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int num = nums[i] * nums[j];
                // 단조 증가 수인지 체크
                if (check(num)) {
                    answer = max(answer, num);
                }
            }
        }

        // 정답 출력
        cout << '#' << tc << ' ' << answer << '\n';
    }

    return 0;
}