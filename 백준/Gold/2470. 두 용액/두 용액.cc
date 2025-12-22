#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int start = 0;
    int end = N - 1;
    int sum = INT_MAX;

    vector<int> answer(2);

    while(start < end) {
        if(abs(v[start] + v[end]) <= sum) {
            answer[0] = v[start];
            answer[1] = v[end];
            sum = abs(v[start] + v[end]);
        }

        if(v[start] + v[end] < 0) {
            start++;
        } else {
            end--;
        }
    }

    cout << answer[0] << ' ' << answer[1] << '\n';

    return 0;
}
