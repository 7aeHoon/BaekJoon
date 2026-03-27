#include <bits/stdc++.h>

using namespace std;

int F, S, G, U, D;
string answer = "use the stairs";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> F >> S >> G >> U >> D;

    // 1층부터 F층 건물
    vector<int> floor(F + 1, -1);

    queue<int> q;

    // S층에서 출발
    q.push(S);
    floor[S] = 0;

    while (!q.empty()) {
        // 현재 엘리베이터가 위치한 층
        int current = q.front();
        q.pop();

        // 만약 엘리베이터가 G층에 도착했을 경우
        if (current == G) {
            break;
        }

        int up = current + U;
        int down = current - D;

        // 상승 이동 가능하고 이미 방문한 경험이 없는 경우
        if (up <= F && floor[up] == -1) {
            q.push(up);
            floor[up] = floor[current] + 1;
        }

        // 하강 이동 가능하고 이미 방문한 경험이 없는 경우
        if (down >= 1 && floor[down] == -1) {
            q.push(down);
            floor[down] = floor[current] + 1;
        }
    }

    // 엘리베이터로 이동 가능할 경우
    if (floor[G] != -1) {
        answer = to_string(floor[G]);
    }

    // 결과 출력
    cout << answer << '\n';

    return 0;
}