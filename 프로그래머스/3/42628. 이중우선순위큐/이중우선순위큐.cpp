#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    multiset<int> ms;

    for (const string& operation : operations) {
        string cmd;
        int num;

        istringstream ss(operation);

        ss >> cmd >> num;

        // 큐에서 삭제
        if (cmd == "D" && !ms.empty()) {
            // 최댓값을 삭제
            if (num == 1) {
                ms.erase(prev(ms.end()));
            }
            // 최솟값을 삭제
            else {
                ms.erase(ms.begin());
            }
        }
        // 큐에 주어진 숫자를 삽입
        else if (cmd == "I") {
            ms.insert(num);
        }
    }

    if (ms.empty()) {
        return {0, 0};
    }

    answer = {*ms.rbegin(), *ms.begin()};

    return answer;
}