#include <bits/stdc++.h>

using namespace std;

struct Info {
    long long t;
    long long a;
    long long h;
};

long long N, answer = LLONG_MAX;
long long wAttack, wHP;

vector<Info> v;

bool isComplete(long long hp, long long attack) {
    // 던전 시작 전 최대 HP 설정
    const long long maxHP = hp;

    for (int i = 0; i < N; i++) {
        // 던전에 용이 있을 경우
        if (v[i].t == 1) {
            // 용사가 용을 죽이는 턴 수
            long long t1 = (v[i].h + attack - 1) / attack;
            // 용이 용사를 죽이는 턴 수
            long long t2 = (hp + v[i].a - 1) / v[i].a;
            // 용사가 먼저 죽을 경우
            if (t1 > t2) return false;
            // 전투 후 용사의 체력 갱신
            hp -= v[i].a * (t1 - 1);
        } else {
            // 용사 공격력 증가
            attack += v[i].a;
            // 체력 회복
            hp = min(hp + v[i].h, maxHP);
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> wAttack;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].t >> v[i].a >> v[i].h;
        if(v[i].t == 1) {
            wHP += v[i].a * v[i].h;
        }
    }

    long long l = 1, r = wHP;

    while (l <= r) {
        long long m = l + (r - l) / 2;

        if (isComplete(m, wAttack)) {
            answer = min(answer, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
