#include <bits/stdc++.h>

using namespace std;

int N, maxFriend, answer = 1;
// 학생, 학년
int school[1001][6];
int student[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // i는 학생 번호, j는 학년
    for (int student = 1; student <= N; student++) {
        for (int grade = 1; grade <= 5; grade++) {
            int classroom;
            cin >> classroom;
            school[student][grade] = classroom;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= 5; k++) {
                if (school[i][k] == school[j][k] && i != j) {
                    student[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int totalFriend = 0;
        
        for (int j = 1; j <= N; j++) {
            if (student[i][j]) totalFriend++;
        }

        if(totalFriend > maxFriend) {
            maxFriend = totalFriend;
            answer = i;
        }
    }

    cout << answer << '\n';

    return 0;
}