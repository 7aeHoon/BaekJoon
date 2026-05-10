#include <bits/stdc++.h>

using namespace std;

set<int> nums;
bool visited[10];

bool isPrime(int n) {

    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void dfs(string numbers, string current) {

    // 숫자 생성
    if (!current.empty()) {
        nums.insert(stoi(current));
    }

    for (int i = 0; i < numbers.size(); i++) {

        if (visited[i]) continue;

        visited[i] = true;

        dfs(numbers, current + numbers[i]);

        visited[i] = false;
    }
}

int solution(string numbers) {

    dfs(numbers, "");

    int answer = 0;

    for (int num : nums) {

        if (isPrime(num)) {
            answer++;
        }
    }

    return answer;
}