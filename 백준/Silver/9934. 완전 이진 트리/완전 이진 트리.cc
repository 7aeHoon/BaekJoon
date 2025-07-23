#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int K;
vector<int> v;
vector<vector<int>> result(10);

void go(const vector<int> &v, const int &depth) {
    if (v.size() == 1) {
        result[depth].push_back(v[0]);
        return;
    }

    int mid = v.size() / 2;

    result[depth].push_back(v[mid]);

    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin() + mid + 1, v.end());

    go(left, depth + 1);
    go(right, depth + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> K;

    for (int i = 0; i < pow(2, K) - 1; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    go(v, 0);

    for (int i = 0; i < K; i++) {
        for (int num : result[i]) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}