#include <bits/stdc++.h>

using namespace std;

unordered_set<char> s;

string attach(vector<string> v) {
    string result;

    for (int i = 0; i < v.size(); i++) {
        result += v[i];
        if(i != v.size() -1) {
            result += ' ';
        }
    }

    return result;
}

vector<string> split(string input, string delimiter) {
    vector<string> result;
    string token = "";
    long long pos = input.find(delimiter);

    while (pos != string::npos) {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimiter.size());
    }

    result.push_back(input);
    return result;
}

string registerKey(string str) {
    int n = str.size();

    // 1. 각 단어의 첫 글자 확인
    for (int i = 0; i < n; i++) {
        if (i == 0 || str[i - 1] == ' ') {
            char key = tolower(static_cast<unsigned char>(str[i]));
            if (s.count(key)) continue;

            s.insert(key);

            string replaceWord;
            replaceWord.push_back('[');
            replaceWord.push_back(str[i]);
            replaceWord.push_back(']');

            str.replace(i, 1, replaceWord);
            return str;
        }
    }

    // 2. 문장 전체 탐색
    for (int i = 0; i < n; i++) {
        if (str[i] == ' ') continue;

        char key = tolower(static_cast<unsigned char>(str[i]));
        if (s.count(key)) continue;

        s.insert(key);

        string replaceWord;
        replaceWord.push_back('[');
        replaceWord.push_back(str[i]);
        replaceWord.push_back(']');

        str.replace(i, 1, replaceWord);
        return str;
    }

    return str;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    cin.ignore();

    vector<string> v(N);
    vector<string> answer(N);

    for (int i = 0; i < N; i++) {
        getline(cin, v[i]);
    }

    for (int i = 0; i < N; i++) {
        answer[i] = registerKey(v[i]);
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}
