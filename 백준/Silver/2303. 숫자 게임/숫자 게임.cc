#include <bits/stdc++.h>

using namespace std;

int N, currentMax = INT_MIN, answer;

// 주어진 카드 중 3장을 사용하여 만들 수 있는 가장 큰 일의 자리 수 조회
int getMax(const vector<int>& v) {
    int result = 0;
    int n = v.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = v[i] + v[j] + v[k];
                result = max(result, sum % 10);
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 사람의 수 입력
    cin >> N;

    for (int i = 0; i < N; i++) {
        // 처음에 주어지는 5개의 카드 리스트
        vector<int> cardList(5);
        // 카드 번호 입력
        for (int j = 0; j < 5; j++) {
            cin >> cardList[j];
        }
        // 주어진 카드 리스트로 만든 가장 큰 값
        int maxSum = getMax(cardList);
        // 만약 이전의 값보다 현재 값이 이상일 경우
        if (currentMax <= maxSum) {
            currentMax = maxSum;
            answer = i + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}