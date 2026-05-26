#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    ll queueOneSum = 0, queueTwoSum = 0, answer = 0;
    ll totalQueueSize = (queue1.size() + queue2.size()) * 2;

    queue<int> queueOne, queueTwo;

    for (const int& num : queue1) {
        queueOne.push(num);
        queueOneSum += num;
    }

    for (const int& num : queue2) {
        queueTwo.push(num);
        queueTwoSum += num;
    }

    // 모든 정수의 합이 홀수일 경우
    if ((queueOneSum + queueTwoSum) % 2 != 0) {
        return -1;
    }

    while (totalQueueSize--) {
        // 두 큐의 합이 같을 경우
        if (queueOneSum == queueTwoSum) {
            return answer;
        }

        // 어느 한 쪽의 큐가 비어있을 경우
        if (queueOne.empty() || queueTwo.empty()) {
            return -1;
        }

        if (queueOneSum > queueTwoSum) {
            if (!queueOne.empty()) {
                int num = queueOne.front();
                queueOne.pop();
                queueOneSum -= num;

                queueTwo.push(num);
                queueTwoSum += num;
            } else {
                break;
            }
        } else {
            if (!queueTwo.empty()) {
                int num = queueTwo.front();
                queueTwo.pop();
                queueTwoSum -= num;

                queueOne.push(num);
                queueOneSum += num;
            } else {
                break;
            }
        }

        answer++;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solution({3, 2, 7, 2}, {4, 6, 5, 1}) << '\n';
    cout << solution({1, 2, 1, 2}, {1, 10, 1, 2}) << '\n';
    cout << solution({2}, {2}) << '\n';
    cout << solution({1, 3}, {3, 1}) << '\n';

    return 0;
}