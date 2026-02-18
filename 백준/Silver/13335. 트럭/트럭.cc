#include <bits/stdc++.h>

using namespace std;

int N, L, W, answer;
int currentTime, currentWeight;
queue<int> watingTruck;
queue<pair<int, int>> bridge;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L >> W;

    for (int i = 0; i < N; i++) {
        int truck;
        cin >> truck;
        watingTruck.push(truck);
    }

    // 대기 중인 트럭이 있거나 다리에 트럭이 있을 경우
    while (!watingTruck.empty() || !bridge.empty()) {
        currentTime++;
        // 현재 다리에 트럭이 있다면
        if (!bridge.empty()) {
            // 나갈 트럭이 있다면
            if (currentTime - bridge.front().second >= L) {
                // 트럭이 나가면서 다리의 현재 하중 빼기
                currentWeight -= bridge.front().first;
                // 선두 트럭 나가기
                bridge.pop();
            }
        }

        // 대기 중인 트럭이 있다면
        if (!watingTruck.empty()) {
            // 트럭이 올라가 다리가 버틸 수 있는 하중일 경우
            if (currentWeight + watingTruck.front() <= W) {
                // 현재 다리의 하중 누적
                currentWeight += watingTruck.front();
                // 다리에 트럭 올리기
                bridge.push({watingTruck.front(), currentTime});
                watingTruck.pop();
            }
        }
    }

    answer = currentTime;

    cout << answer << '\n';

    return 0;
}