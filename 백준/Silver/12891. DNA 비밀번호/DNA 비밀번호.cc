#include <bits/stdc++.h>
using namespace std;

int need[4];      // 필요한 최소 개수 (A, C, G, T)
int nowCnt[4];    // 현재 윈도우 개수 (A, C, G, T)

// 조건 체크 함수 (nowCnt가 need 이상인지 확인)
bool check() {
    return nowCnt[0] >= need[0] &&
           nowCnt[1] >= need[1] &&
           nowCnt[2] >= need[2] &&
           nowCnt[3] >= need[3];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S, P;
    cin >> S >> P;

    string dna;
    cin >> dna;

    cin >> need[0] >> need[1] >> need[2] >> need[3];

    // 초기 윈도우 구성
    for (int i = 0; i < P; i++) {
        char c = dna[i];
        if (c == 'A') nowCnt[0]++;
        else if (c == 'C') nowCnt[1]++;
        else if (c == 'G') nowCnt[2]++;
        else if (c == 'T') nowCnt[3]++;
    }

    int answer = 0;

    // 초기 체크
    if (check()) answer++;

    // 슬라이딩 윈도우 이동
    for (int i = P; i < S; i++) {
        // 제거되는 문자
        char removeChar = dna[i - P];
        if (removeChar == 'A') nowCnt[0]--;
        else if (removeChar == 'C') nowCnt[1]--;
        else if (removeChar == 'G') nowCnt[2]--;
        else if (removeChar == 'T') nowCnt[3]--;

        // 새로 추가되는 문자
        char addChar = dna[i];
        if (addChar == 'A') nowCnt[0]++;
        else if (addChar == 'C') nowCnt[1]++;
        else if (addChar == 'G') nowCnt[2]++;
        else if (addChar == 'T') nowCnt[3]++;

        if (check()) answer++;
    }

    cout << answer << '\n';
    return 0;
}
