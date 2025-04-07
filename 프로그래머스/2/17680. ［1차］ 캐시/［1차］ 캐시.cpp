#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    // 캐시의 사이즈가 0일 경우
    if(cacheSize == 0) { return cities.size() * 5; }

    // 대소문자를 구분하지 않도록 도시이름 수정 
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].size(); j++) {
            if (isupper(cities[i][j])) {
                cities[i][j] = tolower(cities[i][j]);
            }
        }
    }

    for (int i = 0; i < cities.size(); i++) {
        // 캐시에 존재하는지 검색
        auto it = find(cache.begin(), cache.end(), cities[i]);
        // 캐시에 존재한다면
        if (it != cache.end()) {
            cache.erase(it);
            cache.push_back(cities[i]);
            answer += 1;
        } else {
            if (cache.size() >= cacheSize) {
                cache.erase(cache.begin());
            }
            cache.push_back(cities[i]);
            answer += 5;
        }
    }

    return answer;
}