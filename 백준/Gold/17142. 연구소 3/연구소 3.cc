#include <bits/stdc++.h>

using namespace std;

int N, M, answer = INT_MAX;
int emptySpaceCnt = 0;
char lab[51][51];
int visited[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> viruses;

void clear() { fill(&visited[0][0], &visited[0][0] + (51 * 51), -1); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];

            // 벽일 경우
            if (lab[i][j] == '1') {
                lab[i][j] = '-';
                continue;
            }

            // 바이러스일 경우
            if (lab[i][j] == '2') {
                lab[i][j] = '*';
                viruses.push_back({i, j});
                continue;
            }
            // 빈 칸의 수 증가
            emptySpaceCnt++;
        }
    }

    if (emptySpaceCnt == 0) {
        cout << 0 << '\n';
        return 0;
    }

    // 연구소에 존재하는 바이러스 수
    int virusCnt = viruses.size();

    // 비트마스킹으로 M개의 바이러스 추출
    for (int mask = 1; mask < (1 << virusCnt); mask++) {
        clear();
        // 선택된 바이러스의 좌표
        vector<pair<int, int>> selectedViruses;

        for (int i = 0; i < virusCnt; i++) {
            if (mask & (1 << i)) {
                // 선택된 바이러스를 저장
                selectedViruses.push_back(viruses[i]);
            }
        }

        // 정확히 M개의 바이러스를 뽑지 못 했을 경우 패스
        if (selectedViruses.size() != M) continue;

        queue<pair<int, int>> q;

        for (const auto virus : selectedViruses) {
            q.push(virus);
            visited[virus.first][virus.second] = 0;
        }

        // BFS로 바이러스 전파
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                // 영역 밖일 경우
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                // 벽 또는 이미 방문한 빈 칸일 경우
                if (lab[ny][nx] == '-' || visited[ny][nx] != -1) continue;

                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }

        int checked = 0;
        int _max = INT_MIN;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (lab[i][j] == '0' && visited[i][j] != -1) {
                    checked++;
                    _max = max(_max, visited[i][j]);
                }
            }
        }

        if (checked == emptySpaceCnt) {
            answer = min(answer, _max);
        }
    }

    if (answer == INT_MAX) {
        answer = -1;
    }

    cout << answer << '\n';

    return 0;
}