#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

queue<pair<int, int>> q;

int solution(vector<int> priorities, int location) {
    int result = 1;
    int index = 0;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }

    sort(priorities.begin(), priorities.end(), greater<int>());

    while (!q.empty()) {
        pair<int, int> front = q.front();

        if(priorities[index] == front.first) {
            if(location == front.second) {
                break;
            } else {
                q.pop();
                index++;
            }
        } else {
            q.pop();
            q.push(front);
        }
    }

    return index + 1;
}