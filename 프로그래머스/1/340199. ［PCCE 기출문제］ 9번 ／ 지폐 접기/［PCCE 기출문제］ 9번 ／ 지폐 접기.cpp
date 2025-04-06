#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    // 지갑과 지폐의 가로, 세로 길이를 각각 작은 값이 앞에 오도록 정렬
    sort(wallet.begin(), wallet.end());
    sort(bill.begin(), bill.end());

    // 지폐가 지갑에 들어갈 크기가 될 때까지 반복
    while (bill[1] > wallet[1] || bill[0] > wallet[0]) {
        // 큰 쪽을 반으로 접고 소수점 버림
        bill[1] /= 2;
        answer++;

        // bill을 다시 정렬하여 큰 값이 항상 bill[1]에 오도록 유지
        sort(bill.begin(), bill.end());
    }

    return answer;
}