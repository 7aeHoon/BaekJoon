#include <bits/stdc++.h>

using namespace std;

int T, N, answer;

vector<pair<int, int>> v;
vector<pair<int, int>> wires;

void init() {
    answer = 0;
    v.clear();
    wires.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        // 전선의 수
        cin >> N;

        // 전선의 정보 입력
        for (int j = 0; j < N; j++) {
            int A, B;
            cin >> A >> B;
            v.push_back({A, B});
        }

        // 전선 하나 먼저 설치
        wires.push_back(v[0]);

        // 이후부터 나머지 전선 설치
        for (int j = 1; j < N; j++) {
            // 이전에 설치된 전선 정보
            for(auto wire : wires) {
                // 한쪽에서 더 낮으나 다른 한쪽에서는 높은 경우
                if(v[j].first < wire.first && v[j].second > wire.second) answer++;
                // 한쪽에서 더 높으나 다른 한쪽에서는 낮은 경우
                if(v[j].first > wire.first && v[j].second < wire.second) answer++;
            }
            wires.push_back(v[j]);
        }

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}