#include <bits/stdc++.h>

using namespace std;

int T, N, Q, answer;
int arr[1005];

void init() { 
    
    memset(arr, 0, sizeof(arr)); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        cin >> N >> Q;

        for (int j = 1; j <= Q; j++) {
            int L, R;
            cin >> L >> R;
            for (int k = L; k <= R; k++) {
                arr[k] = j;
            }
        }

        // 결과 출력
        cout << '#' << i << ' ';
        for (int j = 1; j <= N; j++) {
            cout << arr[j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}