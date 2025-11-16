#include <bits/stdc++.h>

using namespace std;

int T, answer;
int arr[7];
vector<int> sum;

void init() { 
    sum.clear();    
}

void dfs(const int& index, const int& cnt, const int& total) {
    // 기저사례 설정
    if (cnt == 3) {
        sum.push_back(total);
        return;
    }

    for (int i = index; i < 7; i++) {
        dfs(i + 1, cnt + 1, total + arr[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        // 초기화 진행
        init();

        for (int j = 0; j < 7; j++) {
            cin >> arr[j];
        }

        dfs(0, 0, 0);

        // 계산된 합들을 내림차순으로 정렬
        sort(sum.begin(), sum.end(), greater<int>());
        
        // 중복 제거
        sum.erase(unique(sum.begin(), sum.end()), sum.end());

        // 5번째로 큰 수
        answer = sum[4];

        // 결과 출력
        cout << '#' << i << ' ' << answer << '\n';
    }

    return 0;
}