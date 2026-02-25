#include <bits/stdc++.h>

using namespace std;

int A, P, num, answer;
bool visited[500000];
vector<int> v;

int funcD(int num) {
    int result = 0;

    while (num != 0) {
        int r = num % 10;
        int sum = 1;
        for (int i = 0; i < P; i++) {
            sum *= r;
        }
        result += sum;
        num /= 10;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> P;

    v.push_back(A);
    visited[A] = true;

    while (true) {
        int last = v.back();
        int next = funcD(last);
        if (visited[next]) {
            num = next;
            break;
        }
        v.push_back(next);
        visited[next] = true;
    }

    for (const int& n : v) {
        if (num == n) break;
        answer++;
    }

    cout << answer << '\n';

    return 0;
}