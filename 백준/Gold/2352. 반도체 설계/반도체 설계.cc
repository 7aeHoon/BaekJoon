#include <bits/stdc++.h>

using namespace std;

int N, answer;

vector<int> getLis(const vector<int> &v) {
    vector<int> lis;

    for(const auto& num : v) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if(it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }

    return lis;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> lis = getLis(v);

    answer = lis.size();

    cout << answer << '\n';

    return 0;
}
