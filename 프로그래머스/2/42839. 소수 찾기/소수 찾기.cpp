#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000000;
bool isPrime[MAX + 1];
bool visited[8];
unordered_set<int> us;

void dfs(string current, const string& numbers) {
    int size = numbers.size();

    if (!current.empty()) {
        us.insert(stoi(current));
        cout << stoi(current) << '\n';
    }

    for (int i = 0; i < size; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        dfs(current + numbers[i], numbers);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;

    fill(isPrime, isPrime + MAX + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (!isPrime[i]) continue;

        for (int j = i + i; j <= MAX; j += i) {
            isPrime[j] = false;
        }
    }

    dfs("", numbers);

    for (const int& num : us) {
        if (isPrime[num]) {
            answer++;
        }
    }

    return answer;
}