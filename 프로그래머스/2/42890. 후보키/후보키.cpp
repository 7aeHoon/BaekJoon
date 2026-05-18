#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;

    // 행 개수
    int n = relation.size();

    // 컬럼 개수
    int m = relation[0].size();

    // 후보키 mask 저장
    vector<int> candidateKeys;

    // 모든 컬럼 조합 탐색
    for (int mask = 1; mask < (1 << m); mask++) {

        // -------------------------
        // 최소성 검사
        // -------------------------
        bool isMinimal = true;

        for (const int& key : candidateKeys) {

            // 이미 존재하는 후보키가 부분집합이면 실패
            if ((key & mask) == key) {
                isMinimal = false;
                break;
            }
        }

        if (!isMinimal) continue;

        // -------------------------
        // 유일성 검사
        // -------------------------
        set<vector<string>> s;

        for (int i = 0; i < n; i++) {

            vector<string> tuple;

            for (int j = 0; j < m; j++) {

                // 현재 조합에 포함된 컬럼
                if (mask & (1 << j)) {
                    tuple.push_back(relation[i][j]);
                }
            }

            s.insert(tuple);
        }

        // 모든 튜플이 서로 다름
        if (s.size() == n) {
            candidateKeys.push_back(mask);
            answer++;
        }
    }

    return answer;
}