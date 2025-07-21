#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int K, N;
    cin >> K >> N;

    long long start = 1, end = 1, answer = 0;
    vector<int> v;

    for (int i = 0; i < K; i++) {
        long long length;
        cin >> length;
        v.push_back(length);
        end = max(end, length);
    }

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long cnt = 0;

        for (const auto &length : v) {
            cnt += length / mid;
        }

        if (N <= cnt) {
            start = mid + 1;
            answer = mid;
        } else {
            end = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}