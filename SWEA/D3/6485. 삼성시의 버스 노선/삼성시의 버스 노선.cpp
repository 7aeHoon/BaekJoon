#include <bits/stdc++.h>

using namespace std;

int T, N, P;
int bus[5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 수 입력
    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 노선의 수 입력
        cin >> N;

        memset(bus, 0, sizeof(bus));

        for (int j = 0; j < N; j++) {
            int a, b;
            // 버스의 노선 입력
            cin >> a >> b;
            for (int k = a; k <= b; k++) {
                // k번 버스 정류장의 노선 빈도 증가
                bus[k]++;
            }
        }

        // 노선 정보를 얻고자하는 정류장의 수 입력
        cin >> P;

        // 해당 정류장의 노선 빈도를 저장하는 벡터
        vector<int> v;

        for (int j = 0; j < P; j++) {
            int num;
            // 정류장 번호 입력
            cin >> num;
            // 해당 정류장을 거치는 노선의 수
            v.push_back(bus[num]); 
        }

        cout << '#' << i << ' ';

        for(auto cnt : v) {
            cout << cnt << ' ';
        }
        cout << '\n';
    }

    return 0;
}