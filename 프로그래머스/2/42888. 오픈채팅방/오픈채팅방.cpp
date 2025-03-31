#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// 문자열 input을 구분자 delimiter를 기준으로 분리
vector<string> split(string input, string delimiter) {
    // 결과
    vector<string> result;
    // 현재 인덱스 위치
    int pos = 0;
    // 분리된 문자를 임시 저장
    string token = "";

    // 구분자를 찾고 해당 위치를 저장
    while ((pos = input.find(delimiter)) != string::npos) {
        // 0부터 pos개의 부분 문자열을 token에 임시 저장 
        token = input.substr(0, pos);
        // 구분자에 의해 분리된 token 문자열을 result에 저장
        result.push_back(token);
        // 0부터 (구분자의 위치 + 구분자의 사이즈)만큼 input 문자열에서 제거 
        input.erase(0, pos + delimiter.size());
    }
    
    // 마지막으로 남겨진 input을 result에 추가
    result.push_back(input);

    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    // 오픈 채팅방의 이벤트 벡터
    vector<pair<string, string>> events;
    // 오픈 채팅방 사용자의 아이디와 닉네임 매칭  
    map<string, string> nickname;
    
    for (string str : record) {
        vector<string> v = split(str, " ");
        if (v[0] == "Enter") {
            events.push_back({v[0], v[1]});
            nickname[v[1]] = v[2];
        } else if (v[0] == "Leave") {
            events.push_back({v[0], v[1]});
        } else {
            nickname[v[1]] = v[2];
        }
    }

    for(auto event : events) {
        string word = event.first == "Enter" ? "님이 들어왔습니다." : "님이 나갔습니다.";
        answer.push_back(nickname[event.second] + word);
    }

    return answer;
}