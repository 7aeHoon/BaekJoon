#include <bits/stdc++.h>

using namespace std;

int N, M, answerDist;
string answerDna;
string dna[1001];
map<char, int> m;

char getMostFreq() {
    char ch = 'A';
    int cnt = 0;

    for (const auto& p : m) {
        if (cnt < p.second) {
            ch = p.first;
            cnt = p.second;
        }
    }

    return ch;
}

int getDiffCnt(char ch) {
    int result = 0;

    for (const auto& p : m) {
        if (ch != p.first) result += p.second;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> dna[i];
    }

    for (int i = 0; i < M; i++) {
        // 등장 조회
        for (int j = 0; j < N; j++) {
            char ch = dna[j][i];
            m[ch]++;
        }
        // 가장 많이 등장한 문자 찾기
        char mostChar = getMostFreq();
        // 결과 DNA 문자열에 붙이기
        answerDna += mostChar;
        // 많이 등장한 문자와 다른 문자 수 찾기
        answerDist += getDiffCnt(mostChar);
        // 초기화
        m.clear();
    }

    cout << answerDna << '\n' << answerDist << '\n';

    return 0;
}