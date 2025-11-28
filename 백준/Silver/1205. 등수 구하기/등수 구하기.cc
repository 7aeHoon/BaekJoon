#include <bits/stdc++.h>

using namespace std;

int N, score, P, answer;
map<int, int, greater<int>> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> score >> P;

    m[score]++;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        m[num]++;
    }

    int grade = 1, cnt = 0;

    for (const auto& p : m) {
        cnt += p.second;
        if (p.first == score) {
            answer = grade;
            break;
        } else {
            grade += p.second;
        }
    }

    cout << (cnt <= P ? answer : -1) << '\n';

    return 0;
}
