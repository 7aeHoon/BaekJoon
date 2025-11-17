#include <bits/stdc++.h>

using namespace std;

int T, N, M;
string answer;

void init() { answer = "ON"; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화
        init();

        // 각 카드의 종류
        vector<int> space(14), dia(14), heart(14), clover(14);

        // 각 카드 종류에 따른 부족한 카드 수
        int spaceCnt, diaCnt, heartCnt, cloverCnt;

        // 초기 13장이 부족함
        spaceCnt = diaCnt = heartCnt = cloverCnt = 13;

        // 정상적인 카드인지
        bool flag = true;

        string s;

        cin >> s;

        for (int j = 0; j < s.size(); j += 3) {
            // 카드의 종류
            char type = s[j];

            string numStr = "";
            numStr += s[j + 1];
            numStr += s[j + 2];

            // 정수로 변환
            int num = stoi(numStr);

            // 스페이스
            if (type == 'S') {
                if (space[num] == 0) {
                    space[num]++;
                    spaceCnt--;
                } else {
                    flag = false;
                }
            }
            // 다이아
            else if (type == 'D') {
                if (dia[num] == 0) {
                    dia[num]++;
                    diaCnt--;
                } else {
                    flag = false;
                }
            }
            // 하트
            else if (type == 'H') {
                if (heart[num] == 0) {
                    heart[num]++;
                    heartCnt--;
                } else {
                    flag = false;
                }
            }
            // 클로버
            else {
                if (clover[num] == 0) {
                    clover[num]++;
                    cloverCnt--;
                } else {
                    flag = false;
                }
            }

            if (!flag) break;
        }

        if (!flag) {
            cout << '#' << i << ' ' << "ERROR" << '\n';
        } else {
            cout << '#' << i << ' ' << spaceCnt << ' ' << diaCnt << ' ' << heartCnt << ' ' << cloverCnt << '\n';
        }
        
    }

    return 0;
}
