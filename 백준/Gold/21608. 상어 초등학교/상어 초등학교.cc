#include <bits/stdc++.h>

using namespace std;

int N, answer;
int classroom[21][21];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> order;
vector<int> likeStudent[401];

struct Seat {
    int y;
    int x;
    int emptyCnt;
    int likeCnt;
};

bool cmp(const Seat& l, const Seat& r) {
    if (l.likeCnt != r.likeCnt) return l.likeCnt > r.likeCnt;
    if (l.emptyCnt != r.emptyCnt) return l.emptyCnt > r.emptyCnt;
    if (l.y != r.y) return l.y < r.y;
    return l.x < r.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int totalStudent = N * N;

    for (int i = 0; i < totalStudent; i++) {
        int stu;
        cin >> stu;

        order.push_back(stu);

        for (int j = 0; j < 4; j++) {
            int likeStu;
            cin >> likeStu;

            likeStudent[stu].push_back(likeStu);
        }
    }

    for (int i = 0; i < totalStudent; i++) {
        int stu = order[i];
        vector<Seat> candidate;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (classroom[y][x] != 0) continue;

                int emptyCnt = 0;
                int likeCnt = 0;

                for (int j = 0; j < 4; j++) {
                    int ny = y + dy[j];
                    int nx = x + dx[j];

                    if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                    if (classroom[ny][nx] == 0) {
                        emptyCnt++;
                    } else {
                        for (int k = 0; k < 4; k++) {
                            if (classroom[ny][nx] == likeStudent[stu][k]) {
                                likeCnt++;
                                break;
                            }
                        }
                    }
                }
                candidate.push_back({y, x, emptyCnt, likeCnt});
            }
        }
        sort(candidate.begin(), candidate.end(), cmp);
        classroom[candidate[0].y][candidate[0].x] = stu;
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int likeCnt = 0;
            int stu = classroom[y][x];

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

                for (int j = 0; j < 4; j++) {
                    if (classroom[ny][nx] == likeStudent[stu][j]) {
                        likeCnt++;
                        break;
                    }
                }
            }
            if (likeCnt > 0) answer += pow(10, likeCnt - 1);
        }
    }

    // 결과 출력
    cout << answer << '\n';

    return 0;
}