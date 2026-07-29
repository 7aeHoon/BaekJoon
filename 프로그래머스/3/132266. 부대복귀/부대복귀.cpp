#include <bits/stdc++.h>

using namespace std;

/*
    - 두 지역 간의 길을 통과하는 데 걸리는 시간은 모두 1
    - 지도 정보를 이용하여 최단시간에 부대로 복귀
    - 따라서 BFS
    - 방문할 수 없을 경우 최단거리는 -1
    - destination에서 출발하여 최단거리를 조사한 후 마지막에 sources 정보 출력
*/

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    // 인접 리스트
    vector<int> adj[n + 1];

    // 두 지역을 왕복할 수 있는 길의 정보 조회
    for (const vector<int>& road : roads) {
        int from = road[0];
        int to = road[1];

        // 동일한 정보가 주어지지 않기 때문에 set이 아닌 벡터에 넣어도 무방
        // 두 지역은 연결되어 있어 양방향으로 연결하여 관리
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    queue<int> q;
    vector<int> visited(n + 1, -1);

    // 해당 지역을 큐에 삽입하고 방문 처리
    q.push(destination);
    visited[destination] = 0;

    while (!q.empty()) {
        // 현재 지역
        int current = q.front();
        q.pop();

        // 현재 지역에서 이동할 수 있는 다음 지역 조회
        for (const int& next : adj[current]) {
            // 이미 방문한 지역
            if (visited[next] != -1) continue;

            // 다음으로 방문할 지역은 현재 위치에서 +1칸 이동
            visited[next] = visited[current] + 1;
            // 다음 방문 지역 큐에 삽입
            q.push(next);
        }
    }

    for (const int& source : sources) {
        // 강철부대의 지역에서 해당 지역까지의 거리
        int dist = visited[source];
        answer.push_back(dist);
    }

    return answer;
}