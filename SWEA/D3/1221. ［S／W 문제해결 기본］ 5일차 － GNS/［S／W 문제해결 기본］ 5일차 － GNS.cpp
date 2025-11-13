#include <bits/stdc++.h>

using namespace std;

string words[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
int wordCnt[10];

int toNum(const string& s) {
    for (int i = 0; i < 10; i++) {
        if (words[i] == s) return i;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        string testStr;
        int N;

        memset(wordCnt, 0, sizeof(wordCnt));

        cin >> testStr >> N;

        for (int j = 0; j < N; j++) {
            string s;
            cin >> s;
            wordCnt[toNum(s)]++;
        }

        cout << testStr << '\n';

        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < wordCnt[j]; k++) {
                cout << words[j] << ' ';
            }
        }
        
        cout << '\n';
    }

    return 0;
}