#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N, K;
queue<int> q;
int visited[100005];
long long cnt[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    // 수빈이와 동생의 좌표가 같을 때
    if (N == K) {
        cout << 0 << '\n' << 1 << '\n';
        return 0;
    }

    visited[N] = 1;
    cnt[N] = 1;
    q.push(N);

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int there : {here - 1, here + 1, here * 2}) {
            if (0 <= there && there <= 100000) {
                if (!visited[there]) {
                    q.push(there);
                    visited[there] = visited[here] + 1;
                    cnt[there] += cnt[here];
                } else if (visited[there] == visited[here] + 1) {
                    cnt[there] += cnt[here];
                }
            }
        }
    }

    cout << visited[K] - 1 << '\n';
    cout << cnt[K] << '\n';

    return 0;
}