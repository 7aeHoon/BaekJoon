#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    
    vector<int> belt(N);
    for (int i = 0; i < N; i++) {
        cin >> belt[i];
    }
    
    // 초밥 등장 횟수를 기록하는 배열 (초밥 번호는 1~d)
    vector<int> sushi(d+1, 0);
    int currentCount = 0;
    
    // 초기 윈도우 설정: [0, k-1]
    for (int i = 0; i < k; i++) {
        if (sushi[belt[i]] == 0) {
            currentCount++;
        }
        sushi[belt[i]]++;
    }
    
    // 쿠폰 초밥 고려
    int answer = currentCount + (sushi[c] == 0 ? 1 : 0);
    
    // 슬라이딩 윈도우 처리 (원형 배열 처리)
    for (int i = 1; i < N; i++) {
        // 윈도우에서 빠지는 초밥 처리
        int leftSushi = belt[i - 1];
        sushi[leftSushi]--;
        if (sushi[leftSushi] == 0) {
            currentCount--;
        }
        
        // 새로 들어오는 초밥 처리
        int newIndex = (i + k - 1) % N;
        int newSushi = belt[newIndex];
        if (sushi[newSushi] == 0) {
            currentCount++;
        }
        sushi[newSushi]++;
        
        // 현재 윈도우에 쿠폰 초밥 추가 가능 여부 확인
        int tempAnswer = currentCount + (sushi[c] == 0 ? 1 : 0);
        answer = max(answer, tempAnswer);
    }
    
    cout << answer << "\n";
    return 0;
}
