#include <bits/stdc++.h>

using namespace std;

string X, answer = "NO";
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> X;

    // X가 2자리 수 이상일 경우 계속 반복
    while (X.size() >= 2) {
        int sum = 0;
        // 문자를 정수로 변환 후 누적
        for (char ch : X) {
            sum += ch - '0';
        }
        // 문자열로 변환
        X = to_string(sum);
        cnt++;
    }

    // 만약 3의 배수일 경우
    if (X == "3" || X == "6" || X == "9") {
        answer = "YES";
    }

    // 결과 출력
    cout << cnt << '\n' << answer << '\n';

    return 0;
}