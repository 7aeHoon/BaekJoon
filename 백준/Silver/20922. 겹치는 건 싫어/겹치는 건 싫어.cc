#include <bits/stdc++.h>
using namespace std;

int answer;
int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    deque<int> deq;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        while (arr[num] >= K) {
            arr[deq.front()]--;
            deq.pop_front();
        }

        deq.push_back(num);
        arr[num]++;

        answer = max(answer, (int)deq.size());
    }

    cout << answer << '\n';
    return 0;
}
