#include <bits/stdc++.h>

using namespace std;

int N, len, answer;
vector<string> ids;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    ids.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> ids[i];
    }

    // 학생 번호의 길이
    len = ids[0].size();

    for (int idx = len - 1; idx >= 0; idx--) {
        // 중복 여부 검사
        unordered_set<string> checkedId;
        bool isAllUnique = true; 

        for (const string& id : ids) {
            // 아이디의 부분 문자열 추출
            string subStr = id.substr(idx);
            // 중복된 아이디가 이미 있을 경우
            if (!checkedId.insert(subStr).second) {
                isAllUnique = false;
                break;
            }
        }

        // 모두 중복없이 고유 값을 가질 경우
        if(isAllUnique) {
            answer = len - idx;
            break;
        }
    }

    cout << answer << '\n';

    return 0;
}