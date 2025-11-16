#include <bits/stdc++.h>

using namespace std;

int T, minAns, maxAns;
string s;

void init() {
    minAns = 1000000000;
    maxAns = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화 진행
        init();

        // 숫자 입력
        cin >> s;

        maxAns = minAns = stoi(s);

        // 쌍 구하기
        for (int j = 0; j < s.size(); j++) {
            for (int k = j + 1; k < s.size(); k++) {
                // 자리를 변경할 임시 문자열
                string temp = s;
                // 자리를 변경
                swap(temp[j], temp[k]);
                // 맨 앞의 수가 0이면 건너뛰기
                if (temp[0] == '0') continue;
                // 문자열을 정수로 변환
                int number = stoi(temp);
                // 최솟값 갱신
                minAns = min(minAns, number);
                // 최댓값 갱신
                maxAns = max(maxAns, number);
            }
        }

        // 결과 출력
        cout << '#' << i << ' ' << minAns << ' ' << maxAns << '\n';
    }

    return 0;
}