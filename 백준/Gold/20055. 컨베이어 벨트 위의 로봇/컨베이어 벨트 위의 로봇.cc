#include <bits/stdc++.h>

using namespace std;

int N, K, answer;
deque<pair<int, bool>> d;

// 벨트 회전하기
void rotateBelt() {
    pair<int, bool> last = d.back();
    d.pop_back();
    d.push_front(last);
}

// 마지막 벨트 로봇 체크 후 내리기
void checkLastBelt() {
    if (d[N - 1].second) {
        d[N - 1].second = false;
    }
}

// 로봇 이동하기
void moveRobot() {
    for (int i = N - 2; i >= 0; i--) {
        // 현재 칸에 로봇 존재, 다음 칸이 로봇이 없고 내구도가 1이상일 경우
        if (d[i].second && !d[i+1].second && d[i + 1].first >= 1) {
            d[i + 1].second = true;
            d[i + 1].first--;
            d[i].second = false;
        }
    }
}

// 로봇을 벨트에 올리기
void putRobot() {
    // 로봇이 없고 내구도가 존재하다면
    if (d[0].first >= 1 && !d[0].second) {
        d[0].second = true;
        d[0].first--;
    }
}

bool checkDurability() {
    int cnt = 0;

    for (int i = 0; i < 2 * N; i++) {
        if (d[i].first == 0) cnt++;
    }

    return cnt >= K ? true : false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < 2 * N; i++) {
        int durability;
        cin >> durability;
        d.push_back({durability, false});
    }

    while (true) {
        // 단계 시작
        answer++;
        rotateBelt();
        checkLastBelt();
        moveRobot();
        checkLastBelt();
        putRobot();
        // K개 이상의 내구도 0인 칸이 존재할 경우
        if (checkDurability()) break;
    }

    cout << answer << '\n';

    return 0;
}
