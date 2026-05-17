#include <bits/stdc++.h>

using namespace std;

unordered_set<int> unSet;

bool isPrime(const int& num) {
    if (num <= 1) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

void dfs(const string& str, const string& numbers, vector<bool>& visited) {
    if (!str.empty()) {
        unSet.insert(stoi(str));
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        dfs(str + numbers[i], numbers, visited);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> visited(numbers.size(), false);

    dfs("", numbers, visited);

    for (const int& num : unSet) {
        if (isPrime(num)) {
            answer++;
        }
    }

    return answer;
}