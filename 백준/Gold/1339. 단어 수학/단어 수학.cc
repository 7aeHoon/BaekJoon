#include <bits/stdc++.h>

using namespace std;

int N, val = 9, answer;
int sum[26], charToNum[26];
vector<string> words;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    for (const string& word : words) {
        for (int i = 0; i < word.size(); i++) {
            sum[word[i] - 'A'] += pow(10, word.size() - i - 1);
        }
    }

    for (int i = 0; i < 26; i++) {
        if (sum[i] == 0) continue;
        v.push_back({sum[i], i});
    }

    sort(v.begin(), v.end(), greater<>());

    for (int i = 0; i < v.size(); i++) {
        answer += (v[i].first * val--);
    }

    cout << answer << '\n';

    return 0;
}
