#include <bits/stdc++.h>

using namespace std;

int N, M, budgetSum, maxBudget, answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> busgets(N);

    for (int i = 0; i < N; i++) {
        cin >> busgets[i];
        // 지방의 요구 예산 총합
        budgetSum += busgets[i];
        // 지방의 요구 예산 중 최댓값
        maxBudget = max(maxBudget, busgets[i]);
    }

    // 국가의 한정 예산
    cin >> M;

    if (budgetSum > M) {
        int l = 0, r = M;

        // 이분 탐색
        while (l <= r) {
            // 예산 중앙값
            int mid = (l + r) / 2;
            int sum = 0;

            for (const auto& budget : busgets) {
                sum += min(budget, mid);
            }
            
            // 국가 예산값으로 불가능할 경우
            if(sum > M) {
                r = mid - 1;
            } else {
                answer = mid;
                l = mid + 1;
            }
        }
    } else {
        answer = maxBudget;
    }

    cout << answer << '\n';

    return 0;
}
