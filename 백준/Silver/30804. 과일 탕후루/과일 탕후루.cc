#include <bits/stdc++.h>

using namespace std;

int N, answer;
vector<int> v;
unordered_map<int, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // 투 포인터
    int start = 0;

    for (int end = 0; end < N; end++) {
        // 탕후루에 과일 추가
        m[v[end]]++;

        // 꽂힌 과일의 종류가 3종류 이상일 경우
        while (m.size() >= 3) {
            m[v[start]]--;

            if(m[v[start]] == 0) {
                m.erase(v[start]);
            }

            start++;
        }

        answer = max(answer, end - start + 1);
    }

    cout << answer << '\n';

    return 0;
}