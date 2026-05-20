#include <bits/stdc++.h>

using namespace std;

unordered_set<int> unSet;

bool isPrime(const int& num) {
    if(num <= 1) return false;
    
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    
    return true;
}

void dfs(const string& numbers, vector<bool>& visited, const string& current) {
    if(!current.empty()) {
        unSet.insert(stoi(current));
    }
    
    for(int i = 0; i < numbers.size(); i++) {
        if(visited[i]) continue;
        
        visited[i] = true;
        dfs(numbers, visited, current + numbers[i]);
        visited[i] = false;
    }
    
}

int solution(string numbers) {
    int answer = 0;
    int n = numbers.size();
    
    vector<bool> visited(n, false);
    
    dfs(numbers, visited, "");
    
    for(const int& num: unSet) {
        if(isPrime(num)) answer++;
    }
    
    return answer;
}