#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> ropes(N);
    for (int i = 0; i < N; ++i) {
        cin >> ropes[i];
    }

    // 로프의 최대 중량을 내림차순으로 정렬
    sort(ropes.begin(), ropes.end(), greater<int>());

    int max_weight = 0;

    // 각 로프를 사용할 경우의 최대 중량을 계산
    for (int i = 0; i < N; ++i) {
        max_weight = max(max_weight, ropes[i] * (i + 1));
    }

    cout << max_weight << endl;

    return 0;
}