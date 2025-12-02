#include <bits/stdc++.h>

using namespace std;

int num, N, answer;
vector<string> words;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    string firstWord = words[0];

    vector<int> firstCheck(26, 0);

    for (const auto& ch : firstWord) {
        firstCheck[ch - 'A']++;
    }

    for (int i = 1; i < N; i++) {
        int addCnt = 0, deleteCnt = 0;
        bool isSame = true;
        string secondWord = words[i];
        vector<int> secondCheck(26, 0);

        for (const auto& ch : secondWord) {
            secondCheck[ch - 'A']++;
        }

        for (int j = 0; j < 26; j++) {
            if (firstCheck[j] - secondCheck[j] == 0) {
                continue;
            } else if (firstCheck[j] - secondCheck[j] == 1) {
                addCnt++;
            } else if (firstCheck[j] - secondCheck[j] == -1) {
                deleteCnt++;
            } else {
                isSame = false;
                break;
            }
        }
        if (isSame && addCnt <= 1 && deleteCnt <= 1) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}
