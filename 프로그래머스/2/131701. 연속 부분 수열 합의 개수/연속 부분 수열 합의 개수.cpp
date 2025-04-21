#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<int> s;

void slidingWindow(const int& windowSize, const vector<int>& v) {
    int sum = 0;
    int end = v.size() / 2;

    for (int i = 0; i < windowSize; i++) {
        sum += v[i];
    }

    s.insert(sum);

    for (int i = 1; i < end; i++) {
        sum += v[i + windowSize - 1];
        sum -= v[i - 1];
        s.insert(sum);
    }

}

int solution(vector<int> elements) {
    int answer = 0;

    int size = elements.size();

    // 벡터 이어 붙이기
    vector<int> v = elements;
    v.insert(v.end(), elements.begin(), elements.end());

    // 윈도우 사이즈 i
    for (int i = 1; i <= size; i++) {
        slidingWindow(i, v);
    }

    answer = s.size();

    return answer;
}