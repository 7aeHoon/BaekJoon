#include <bits/stdc++.h>

using namespace std;

int before[20];
int answer[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    cin >> P;

    for (int i = 1; i <= P; i++) {
        int tcNum;
        cin >> tcNum;

        vector<int> after;

        for (int j = 0; j < 20; j++) {
            cin >> before[j];
        }

        for (int j = 0; j < 20; j++) {
            for (auto h : after) {
                if(before[j] < h) answer[tcNum]++;
            }

            after.push_back(before[j]);
        }
    }

    for (int i = 1; i <= P; i++) {
        cout << i << ' ' << answer[i] << '\n';
    }

    return 0;
}
