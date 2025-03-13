#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    // 사전순으로 오름차순 정렬
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        int size = min(phone_book[i].size(), phone_book[i + 1].size());
        if (phone_book[i].substr(0, size) == phone_book[i + 1].substr(0, size)) {
            return false;
        }
    }

    return answer;
}