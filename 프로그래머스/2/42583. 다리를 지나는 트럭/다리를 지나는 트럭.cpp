#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> bridge;

    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }

    int time = 0;
    int currentBridgeWeight = 0;
    int currentTruckIndex = 0;

    while (currentTruckIndex < truck_weights.size() || currentBridgeWeight > 0) {
        time++;

        currentBridgeWeight -= bridge.front();
        bridge.pop();

        if (currentTruckIndex < truck_weights.size() && currentBridgeWeight + truck_weights[currentTruckIndex] <= weight) {
            bridge.push(truck_weights[currentTruckIndex]);
            currentBridgeWeight += truck_weights[currentTruckIndex];
            currentTruckIndex++;
        } else {
            bridge.push(0);
        }
    }

    answer = time;

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}