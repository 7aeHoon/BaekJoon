#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// HH:MM을 M으로 변환하는 함수
int convertTimeToMinutes(string hhmm) { return stoi(hhmm.substr(0, 2)) * 60 + stoi(hhmm.substr(3, 2)); }

// input를 delimiter를 기준으로 구분하는 함수
vector<string> splitRecord(string input, string delimiter) {
    vector<string> result;
    int pos = 0;
    string token = "";

    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimiter.size());
    }

    result.push_back(input);

    return result;
}

// 누적 주차 시간을 계산하여 요금을 측정하는 함수
// fees는 (기본시간, 기본요금, 단위시간, 단위요금)
int caculateParkingFee(vector<int> fees, int minutes) {
    // 기본요금 청구
    int result = fees[1];
    // 초과 시간
    int overtime = minutes - fees[0];

    // 초과 시간일 경우
    if (overtime > 0) {
        result += (overtime / fees[2]) * fees[3];
        // 초과 시간 올림
        if (overtime % fees[2] > 0) {
            result += fees[3];
        }
    }

    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    // (차량번호, 시간)
    map<string, string> parking;
    // (차량번호, 사용시간)
    map<string, int> fee;

    for (string record : records) {
        vector<string> v = splitRecord(record, " ");
        // 시각
        string hhmm = v[0];
        // 차량번호
        string carNum = v[1];
        // IN/OUT 내역
        string status = v[2];

        // 출차일 경우
        if (status == "OUT") {
            // 출차 시간 - 입차 시간
            int minutes = convertTimeToMinutes(hhmm) - convertTimeToMinutes(parking[carNum]);
            // 차량 번호에 따라 사용시간 저장
            fee[carNum] += minutes;
            // 입출차 기록 제거
            parking.erase(carNum);
        } else {  // 입차일 경우
            // 차량번호에 따른 입차시간 저장
            parking[carNum] = hhmm;
        }
    }

    for (auto p : parking) {
        // 출차 시간 - 입차 시간
        int minutes = convertTimeToMinutes("23:59") - convertTimeToMinutes(p.second);
        // 차 번호에 따라 주차 요금 저장
        fee[p.first] += minutes;
    }

    for (auto f : fee) {
        // 요금 저장
        answer.push_back(caculateParkingFee(fees, f.second));
    }

    return answer;
}