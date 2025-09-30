#include <bits/stdc++.h>

using namespace std;

int n, answer, sum;
string str;
int check[200005];
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 문자열의 길이 입력
    cin >> n;

    // 문자열 입력
    cin >> str;

    for (int i = 0; i < n; i++) {
        char ch = str[i];

        if (ch == '(') {
            st.push(i);
        }

        if (ch == ')') {
            // 스택에 여는 괄호가 있을 경우
            if (!st.empty()) {
                int index = st.top();
                st.pop();
                // 여는 괄호와 닫는 괄호를 올바른 괄호 문자열로 체크
                check[index] = 1;
                check[i] = 1;
            }
            // 스택에 여는 괄호가 없을 경우
            else {
                check[i] = 0;
            }
        }
    }

    // !스택에 남아있는 여는 괄호는 체크할 필요 없음(초기화를 0으로 설정)
    for (int i = 0; i < n; i++) {
        if (check[i] == 1) {
            sum += 1;
        } else {
            answer = max(answer, sum);
            sum = 0;
        }
    }

    if (sum != 0) {
        answer = max(answer, sum);
    }

    cout << answer << '\n';

    return 0;
}