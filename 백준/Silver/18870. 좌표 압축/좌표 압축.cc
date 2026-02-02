#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    A.resize(N);
    B.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = A[i];
    }

    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    for (const int& num : A) {
        auto iter = lower_bound(B.begin(), B.end(), num);
        int index = iter - B.begin();
        cout << index << ' ';
    }
    
    cout << '\n';

    return 0;
}