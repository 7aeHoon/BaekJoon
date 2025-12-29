#include <bits/stdc++.h>

using namespace std;

int N, M, T, answer;
int circle[51][51];
int temp[51][51];
vector<pair<int, int>> v;

// 임시 저장소 초기화
void init() { memset(temp, 0, sizeof(temp)); }

// 원판을 회전하기
void rotateCircle(int x, int d, int k) {
    // 1차 모듈러
    k %= M;
    // 반시계 방향 회전을 시계 방향 회전으로 수정
    if (d == 1) {
        k = M - k;
        k %= M;
    }
    // 0번 회전은 바로 종료
    if (k == 0) return;

    // 임시로 저장
    for (int i = x - 1; i < N; i += x) {
        for (int j = 0; j < M; j++) {
            temp[i][(j + k) % M] = circle[i][j];
        }
    }

    // 원본에 저장
    for (int i = x - 1; i < N; i += x) {
        for (int j = 0; j < M; j++) {
            circle[i][j] = temp[i][j];
        }
    }
}

// 원판의 인접 수를 체크하기
void checkAdjacency() {
    // 가로 체크
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (circle[i][j] != circle[i][(j + 1) % M]) continue;
            if (circle[i][j] == 0) continue;
            v.push_back({i, j});
            v.push_back({i, (j + 1) % M});
        }
    }

    // 세로 체크
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M; j++) {
            if (circle[i][j] != circle[i + 1][j]) continue;
            if (circle[i][j] == 0) continue;
            v.push_back({i, j});
            v.push_back({i + 1, j});
        }
    }
}

// 인접이 있을 경우, 좌표 리스트를 꺼내 제거하기
void removeAdjacency() {
    for (int i = 0; i < v.size(); i++) {
        pair<int, int> p = v[i];
        circle[p.first][p.second] = 0;
    }

    v.clear();
}

// 인접이 없을 경우, 평균 계산하고, 원판 수 갱신하기
void updateAdjacency() {
    double avg, sum = 0, cnt = 0;
    // 전체 합
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (circle[i][j] != 0) {
                sum += circle[i][j];
                cnt++;
            }
        }
    }
    // 평균
    avg = sum / cnt;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (circle[i][j] == 0) continue;
            if (circle[i][j] > avg)
                circle[i][j]--;
            else if (circle[i][j] < avg)
                circle[i][j]++;
        }
    }
}

// 최종 원판에 적힌 수의 합 계산하기
void calculateSum() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            answer += circle[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> T;

    // 원판에 적힌 수 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> circle[i][j];
        }
    }

    // 회전할 정보 입력
    for (int i = 0; i < T; i++) {
        int x, d, k;
        cin >> x >> d >> k;
        init();
        rotateCircle(x, d, k);
        checkAdjacency();
        v.empty() ? updateAdjacency() : removeAdjacency();
    }

    calculateSum();

    cout << answer << '\n';

    return 0;
}
