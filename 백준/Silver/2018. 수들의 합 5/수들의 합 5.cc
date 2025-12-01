#include <bits/stdc++.h>

using namespace std;

int N, answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int sum = 1;
    int l = 1;
    int r = 1;

    while(l != N) {
        if(sum < N) {
            sum += ++r;
        } else if(sum > N) {
            sum -= l++;
        } else {
            answer++;
            sum += ++r;
        }
    }

    cout << answer + 1 << '\n';

    return 0;
}
