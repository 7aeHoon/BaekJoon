#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;

    queue<int> watingQueue;
    queue<pair<int, int>> bridgeQueue;
    int currentBridgeWeight = 0;
    int completedTruckCount = 0;

    for (const auto& truck_weight : truck_weights) {
        watingQueue.push(truck_weight);
    }

    while (completedTruckCount < truck_weights.size()) {
        // 트럭을 다리에서 먼저 빼내기
        if (!bridgeQueue.empty() && bridgeQueue.front().second == time) {
            currentBridgeWeight -= bridgeQueue.front().first;

            bridgeQueue.pop();

            completedTruckCount++;
        }

        // 트럭을 다리에 올리기
        if (!watingQueue.empty() && watingQueue.front() + currentBridgeWeight <= weight) {
            int currentTruckWeight = watingQueue.front();
            watingQueue.pop();

            bridgeQueue.push({currentTruckWeight, time + bridge_length});

            currentBridgeWeight += currentTruckWeight;
        }

        time++;
    }

    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}