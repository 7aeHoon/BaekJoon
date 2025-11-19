#include <bits/stdc++.h>

using namespace std;

int L, C;
char words[16];
bool visited[16];
string answer;

// 모음과 자음의 조건을 만족하는지 체크
bool isPossiblePassword(string pw) {
    int vowel = 0, consonant = 0;

    for(const auto& ch : pw) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowel++;
        } else {
            consonant++;
        }
    }

    // 1개 이상의 모음과 2개 이상의 자음일 경우 만족 나머지 불만족
    return (vowel >= 1 && consonant >= 2) ? true : false;
}

// 암호 만들기
// 현재까지 누적된 문자열, 모음, 자음
void makePassword(string password, int index) {
    // L개의 문자로 암호를 만들고 유효성도 만족할 경우
    if (password.size() == L && isPossiblePassword(password)) {
        cout << password << '\n';
        return;
    }

    for (int i = index; i < C; i++) {
        // 이미 사용한 문자일 경우
        if (visited[i]) continue;
        // 암호에 사용한 문자로 체크
        visited[i] = true;
        // 현재 문자를 암호에 추가
        makePassword(password + words[i], i + 1);
        // 암호에 사용하지 않은 문자로 원상복구
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 길이가 L인 암호, C개의 문자
    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        // 사용할 수 있는 문자 입력
        cin >> words[i];
    }

    // 문자 오름차순 정렬
    sort(words, words + C);

    // 암호 만들기 시작
    makePassword("", 0);

    return 0;
}
