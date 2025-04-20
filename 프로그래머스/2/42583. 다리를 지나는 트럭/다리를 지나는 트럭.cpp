#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 다리를 건너간 트럭의 수
int completedTruckCnt;
// 현재 다리가 견디고 있는 하중
int currentBridgeWeight;
// 다리를 건너고 있는 트럭의 정보를 저장하는 큐
queue<pair<int, int>> bridgeQueue;
// 대기 중인 트럭을 저장하는 큐
queue<int> watingQueue;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;

    // 트럭를 대기 큐에 삽입
    for (auto truck : truck_weights) {
        watingQueue.push(truck);
    }

    // 모든 트럭이 다리를 건널 때까지 진행
    while (completedTruckCnt < truck_weights.size()) {
        if (!bridgeQueue.empty() && bridgeQueue.front().second == time) {
            currentBridgeWeight -= bridgeQueue.front().first;
            bridgeQueue.pop();
            completedTruckCnt++;
        }

        if (!watingQueue.empty() && currentBridgeWeight + watingQueue.front() <= weight) {
            int truckWeight = watingQueue.front();
            watingQueue.pop();
            bridgeQueue.push({truckWeight, time + bridge_length});
            currentBridgeWeight += truckWeight;
        }

        time++;
    }

    return time;
}