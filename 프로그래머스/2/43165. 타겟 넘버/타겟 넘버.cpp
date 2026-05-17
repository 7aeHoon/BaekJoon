#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = numbers.size();

    for (int mask = 0; mask < (1 << size); mask++) {
        vector<int> op;
        int sum = 0;

        for (int i = 0; i < size; i++) {
            if (mask & (1 << i)) {
                op.push_back(1);
            } else {
                op.push_back(-1);
            }
        }

        for (int i = 0; i < size; i++) {
            sum += op[i] * numbers[i];
        }

        if (sum == target) answer++;
    }

    return answer;
}