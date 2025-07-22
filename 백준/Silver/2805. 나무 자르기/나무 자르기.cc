#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M;
    int start = 0, end = 0;
    long long answer = 0;
    vector<long long> v;

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        int length;
        cin >> length;
        v.push_back(length);
        end = max(end, length);
    }

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long sum = 0;

        for (const auto &l : v) {
            sum += max(l - mid, (long long)0);
        }

        if (M <= sum) {
            answer = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}