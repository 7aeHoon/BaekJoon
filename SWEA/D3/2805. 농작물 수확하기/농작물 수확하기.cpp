#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        int N, answer = 0;
        cin >> N;

        vector<vector<int>> v(N, vector<int>());

        for (int j = 0; j < N; j++) {
            string str;
            cin >> str;

            for (auto ch : str) {
                v[j].push_back(ch - '0');
            }
        }

        int mid = N / 2;

        for (int j = 0; j < N; j++) {
            int diff = abs(mid - j);
            
            vector<int> temp(v[j].begin() + diff, v[j].end() - diff);

            for(auto num : temp) answer += num;
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}
