#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int T;

    // 테스트 케이스 입력
    cin >> T;

    for (int i = 0; i < T; i++) {
        string p, arr, s;
        int n;
        deque<int> dq;
        bool isReverse = false, isError = false;

        // 수행할 함수명, 배열 사이즈, 배열 입력
        cin >> p >> n >> arr;

        for (int j = 0; j < arr.size(); j++) {
            if (isdigit(arr[j])) {
                s += arr[j];
            } else {
                if (!s.empty()) {
                    dq.push_back(stoi(s));
                    s = "";
                }
            }
        }

        // 입력받은 함수 명령 수행
        for (const char &ch : p) {
            if (ch == 'R') {
                isReverse = !isReverse;
            } else {
                if (dq.empty()) {
                    isError = true;
                    break;
                }

                isReverse ? dq.pop_back() : dq.pop_front();
            }
        }

        // 결과 출력
        if (isError) {
            cout << "error" << '\n';
        } else {
            if (dq.empty()) {
                cout << "[]" << '\n';
            } else {
                cout << "[";
                if (isReverse) {
                    for (int j = dq.size() - 1; j >= 0; j--) {
                        cout << dq[j];
                        if (j > 0) {
                            cout << ',';
                        }
                    }
                } else {
                    for (int j = 0; j < dq.size(); j++) {
                        cout << dq[j];
                        if (j < dq.size() - 1) {
                            cout << ',';
                        }
                    }
                }
                cout << "]" << '\n';
            }
        }
    }

    return 0;
}