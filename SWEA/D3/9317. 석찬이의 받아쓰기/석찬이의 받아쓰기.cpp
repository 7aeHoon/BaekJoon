#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        int N, answer = 0;
        string str1, str2;

        cin >> N;
        cin >> str1;
        cin >> str2;

        for (int j = 0; j < N; j++) {
            if(str1[j] == str2[j]) answer++;
        }

        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}