#include <bits/stdc++.h>

using namespace std;

vector<int> getLIS(const vector<int>& v) {
    int N = v.size();
    vector<int> lis;
    vector<int> record(N, -1);

    for (int i = 0; i < N; i++) {
        int num = v[i];
        auto it = lower_bound(lis.begin(), lis.end(), num);
        int pos = it - lis.begin();

        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }

        record[i] = pos;
    }

    vector<int> result;

    int target = lis.size() - 1;

    for (int i = N - 1; i >= 0; i--) {
        if (record[i] == target) {
            result.push_back(v[i]); 
            target--;
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> lis = getLIS(v);

    cout << lis.size() << '\n';

    for (const int& num : lis) {
        cout << num << ' ';
    }

    return 0;
}
