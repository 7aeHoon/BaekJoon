#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 10; i++) {
        string answer, word;
        int N;

        cin >> N;
        cin >> word;

        for(const char& ch: word) {
            if(!answer.empty()) {
                if(answer.back() == ch) {
                    answer.pop_back();
                } else {
                    answer += ch;
                }
            } else {
                answer += ch;
            }
        }

        cout << '#' << i << ' ' << answer << '\n'; 
    }

    return 0;
}