#include <bits/stdc++.h>

using namespace std;

int N, result = 1000;
int population[15];

vector<vector<int>> adj(15);

// 모든 구역이 서로 연결되있는지 확인
bool isConnectedAll(vector<int> v) {
    unordered_set<int> s(v.begin(), v.end());
    unordered_set<int> visited;
    queue<int> q;
    // 초기 구역
    q.push(v[0]);
    // 초기 방문처리
    visited.insert(v[0]);

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int there : adj[here]) {
            // 선거구에 포함된 구역이고, 방문하지 않았을 경우
            if (s.count(there) && !visited.count(there)) {
                q.push(there);
                // 방문처리
                visited.insert(there);
            }
        }
    }
    // 선서구 내 구역 크기와 방문한 구역의 크기가 같은 경우는, 선거구 내 모든 구역은 연결되어 있다는 의미
    return v.size() == visited.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // 구역의 개수 입력
    cin >> N;

    for (int i = 1; i <= N; i++) {
        // 각 구역별 인구수 정보 입력
        cin >> population[i];
    }

    for (int i = 1; i <= N; i++) {
        // 연결된 구역의 수
        int connectedAreaCount;
        cin >> connectedAreaCount;
        for (int j = 1; j <= connectedAreaCount; j++) {
            // 연결된 구역의 번호
            int connectedArea;
            cin >> connectedArea;
            // 해당 구역과 인접리스트로 연결
            adj[i].push_back(connectedArea);
        }
    }

    // 모든 구역이 하나의 선거구에 들어가는 경우는 제외
    for (int i = 1; i < (1 << N) - 1; i++) {
        vector<int> constituencyA;
        vector<int> constituencyB;
        int totalPopulationA = 0;
        int totalPopulationB = 0;

        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                // 선거구 A에 해당 구역 저장
                constituencyA.push_back(j + 1);
            } else {
                // 선거구 B에 해당 구역 저장
                constituencyB.push_back(j + 1);
            }
        }

        // 두 선거구의 구역들이 정상적으로 모두 연결되어있을 때
        if (isConnectedAll(constituencyA) && isConnectedAll(constituencyB)) {
            for (int area : constituencyA) {
                // 선거구 A에 해당하는 구역의 인구수 누적
                totalPopulationA += population[area];
            }
            for (int area : constituencyB) {
                // 선거구 B에 해당하는 구역의 인구수 누적
                totalPopulationB += population[area];
            }
            // 두 선거구의 인구 차이
            int diff = abs(totalPopulationA - totalPopulationB);
            // 결과를 최솟값으로 갱신
            result = min(diff, result);
        }
    }

    // 결과 출력
    cout << ((result == 1000) ? -1 : result) << '\n';

    return 0;
}