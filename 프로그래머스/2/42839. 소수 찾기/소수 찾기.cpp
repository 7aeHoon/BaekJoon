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

void dfs(const string& str, const vector<char>& nums, vector<bool>& visited) {
    if (!str.empty()) {
        unSet.insert(stoi(str));
    }

    for (int i = 0; i < nums.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        dfs(str + nums[i], nums, visited);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;

    vector<char> nums;
    vector<bool> visited;

    for (const char& ch : numbers) {
        nums.push_back(ch);
    }

    visited.resize(nums.size(), false);

    dfs("", nums, visited);

    for (const int& num : unSet) {
        if (isPrime(num)) {
            answer++;
        }
    }

    return answer;
}