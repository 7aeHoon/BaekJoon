#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, from, to, m, answer = -1;
vector<vector<int>> v(101);
int visited[101];

void DFS(const int &here, const int &cnt) {
    if(here == to) {
        answer = cnt;
        return;
    }
    // 방문 처리
    visited[here] = true;
    // 다음 관계 탐색
    for(const auto &there : v[here]) {
        if(visited[there]) { continue; }
        DFS(there, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 사람들의 번호 1 ~ N
    cin >> N; 
    // from -> to 의 관계
    cin >> from >> to;
    // 부모 자식들 간의 관계의 개수 
    cin >> m; 
    // 부모 번호 x, 자식 번호 y
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    // 촌수 탐색
    DFS(from, 0);
    // 두 사람의 촌수를 출력
    cout << answer << '\n';

    return 0;
}