#include <bits/stdc++.h>

using namespace std;

int N, answer;
unordered_map<string, int> in;
vector<int> out;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // 터널에 진입하는 차량 번호 입력
    for (int i = 0; i < N; i++) {
        string carNum;
        cin >> carNum;
        in[carNum] = i;
    }

    // 터널에 진출하는 차량 번호 입력
    for (int i = 0; i < N; i++) {
        string carNum;
        cin >> carNum;
        // 진출하는 차량이 몇 번째로 진입 했는지 조회
        int inCarNum = in[carNum];
        out.push_back(inCarNum);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // 자신의 진입 번호보다 큰 진입 번호를 가진 차량이 있을 경우
            if (out[i] > out[j]) {
                // 카운트 증가
                answer++;
                break;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}