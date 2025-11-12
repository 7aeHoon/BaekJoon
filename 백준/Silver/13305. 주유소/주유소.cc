#include <bits/stdc++.h>

using namespace std;

int N, city, answer;
int dist[100005];
int price[100005];
int pSum[100005];
vector<pair<int, int>> v;

bool compare(pair<int, int> l, pair<int, int> r) { return l.second < r.second; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // N개의 도시 입력
    cin >> N;

    // 현재 도시 번호 설정
    city = N - 1;

    for (int i = 1; i < N; i++) {
        // i - 1번 도시에서 i도시로 갈 때의 거리 입력
        cin >> dist[i];
        pSum[i] = pSum[i - 1] + dist[i];
    }

    for (int i = 0; i < N; i++) {
        // i번 도시의 주유소 기름 가격 입력
        cin >> price[i];
        v.push_back({i, price[i]});
    }

    // 리터 당 가격이 낮은 순으로 오름차순 정렬
    stable_sort(v.begin(), v.end(), compare);

    for (const auto& p : v) {
        // 0번 도시일 경우
        if (p.first == 0) {
            answer += (pSum[city] - pSum[p.first]) * price[p.first];
            break;
        }
        if (p.first < city) {
            answer += (pSum[city] - pSum[p.first]) * price[p.first];
            // 주유 도시 갱신
            city = p.first;
        }
    }

    cout << answer << '\n';

    return 0;
}