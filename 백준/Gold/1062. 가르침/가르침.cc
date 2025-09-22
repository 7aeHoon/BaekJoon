#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> words;
bool visited[26];
int answer = 0;

// 읽을 수 있는 단어 수 계산
int countReadable(int learnedMask) {
    int cnt = 0;
    for (int wordMask : words) {
        if ((wordMask & learnedMask) == wordMask) cnt++;
    }
    return cnt;
}

void dfs(int idx, int cnt, int learnedMask) {
    if (cnt == K) {
        answer = max(answer, countReadable(learnedMask));
        return;
    }
    for (int i = idx; i < 26; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i + 1, cnt + 1, learnedMask | (1 << i));
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    words.resize(N);

    // K < 5면 필수 글자도 못 배움
    if (K < 5) {
        cout << 0 << "\n";
        return 0;
    }

    // 필수 글자 처리
    int baseMask = 0;
    for (char c : {'a', 'n', 't', 'i', 'c'})
        baseMask |= (1 << (c - 'a')), visited[c - 'a'] = true;

    // 단어 입력 → 비트마스크 변환
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        int mask = 0;
        for (char c : word) mask |= (1 << (c - 'a'));
        words[i] = mask;
    }

    dfs(0, 5, baseMask);  // 필수 5개는 이미 포함
    cout << answer << "\n";
}
