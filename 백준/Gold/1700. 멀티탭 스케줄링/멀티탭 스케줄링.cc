#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> page;         // 현재 꽂힌 페이지
    vector<int> list(M);
    for (int i = 0; i < M; i++) cin >> list[i];

    int answer = 0;

    for (int i = 0; i < M; i++) {
        int num = list[i];

        // 이미 존재하면 continue
        bool exist = false;
        for (int p : page) {
            if (p == num) { exist = true; break; }
        }
        if (exist) continue;

        // 공간 있으면 넣기
        if (page.size() < N) {
            page.push_back(num);
            continue;
        }

        // 교체 대상 찾기
        int idx = -1, farthest = -1;
        for (int j = 0; j < page.size(); j++) {
            int next = 1e9;
            for (int k = i + 1; k < M; k++) {
                if (page[j] == list[k]) { next = k; break; }
            }

            // 가장 늦게 쓰일 페이지 선택
            if (next > farthest) {
                farthest = next;
                idx = j;
            }
        }

        page[idx] = num;
        answer++;
    }

    cout << answer << "\n";
    return 0;
}
