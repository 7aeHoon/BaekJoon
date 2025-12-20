#include <bits/stdc++.h>

using namespace std;

int cnt, answer;
int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int start = 0;

    for (int end = 0; end < N; end++) {
        int endNum = v[end];
        // 등장 횟수 증가
        arr[endNum]++;

        // K보다 많이 등장했을 경우
        while(arr[endNum] > K) {
            int startNum = v[start];
            // 등장 횟수 감소
            arr[startNum]--;
            // 시작 포인터 증가
            start++;
        }

        answer = max(answer, end - start + 1);
    }

    cout << answer << '\n';

    return 0;
}
