#include <bits/stdc++.h>

using namespace std;

int N, answer;
vector<int> v;

int getLIS() {
    vector<int> result;

    for (const auto& num : v) {
        auto it = lower_bound(result.begin(), result.end(), num);
        if (it == result.end()) {
            result.push_back(num);
        } else {
            *it = num;
        }
    }

    return result.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    answer = getLIS();

    cout << answer << '\n';

    return 0;
}
