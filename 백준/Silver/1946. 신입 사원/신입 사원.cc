#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    while (TC--) {
        int answer = 0;

        int N;
        cin >> N;

        vector<pair<int, int>> v(N);

        for (int i = 0; i < N; i++) {
            int firstGrade, secondGrade;
            cin >> firstGrade >> secondGrade;

            v[i] = {firstGrade, secondGrade};
        }

        sort(v.begin(), v.end());

        int minGrade = N + 1;

        for (int i = 0; i < N; i++) {
            if(v[i].second < minGrade) {
                minGrade = v[i].second;
                answer++;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
