#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, result = 1;
    vector<int> arr(1005, 0);
    vector<int> DP(1005, 1);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        result = max(result, DP[i]);
    }

    cout << result << '\n';

    return 0;
}