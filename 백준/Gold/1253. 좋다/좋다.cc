#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int answer = 0;

    for (int i = 0; i < N; i++) {
        long long target = a[i];
        int left = 0;
        int right = N - 1;

        bool ok = false;

        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }

            long long sum = a[left] + a[right];

            if (sum == target) {
                ok = true;
                break;
            } else if (sum < target) {
                left++;
            } else { // sum > target
                right--;
            }
        }

        if (ok) answer++;
    }

    cout << answer << '\n';
    return 0;
}
