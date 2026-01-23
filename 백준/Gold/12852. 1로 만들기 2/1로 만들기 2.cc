#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1000005];
int nextPos[1000005];

int go(int num) {
    // 기저사례
    if (num == 1) return 0;

    // 메모이제이션
    if (arr[num] != -1) {
        return arr[num];
    }

    int result = INT_MAX;

    if (num % 3 == 0) {
        int x = go(num / 3) + 1;
        if (result > x) {
            result = x;
            nextPos[num] = num / 3;
        }
    }
    if (num % 2 == 0) {
        int x = go(num / 2) + 1;
        if (result > x) {
            result = x;
            nextPos[num] = num / 2;
        }
    }
    if (num - 1 > 0) {
        int x = go(num - 1) + 1;
        if (result > x) {
            result = x;
            nextPos[num] = num - 1;
        }
    }

    arr[num] = result;

    return arr[num];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    memset(arr, -1, sizeof(arr));
    memset(nextPos, -1, sizeof(nextPos));

    cout << go(N) << '\n';

    while (N != -1) {
        cout << N << ' ';
        N = nextPos[N];
    }

    return 0;
}