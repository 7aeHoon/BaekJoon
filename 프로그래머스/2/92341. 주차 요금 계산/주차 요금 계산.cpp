#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// HH:MM을 총 M으로 변환하는 함수
int convertTimeToMinutes(const string &hhmm) {
    int h = stoi(hhmm.substr(0, 2));
    int m = stoi(hhmm.substr(3, 2));
    return h * 60 + m;
}

// input를 delimiter를 기준으로 구분하는 함수
vector<string> splitRecord(string input, const string &delimiter) {
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
int caculateParkingFee(const vector<int> &fees, int minutes) {
    // 기본 시간과 기본 요금
    int baseTime = fees[0], bassFee = fees[1];
    // 초과시간 당 초과 요금
    int unitTime = fees[2], unitFee = fees[3];
    // 요금
    int total = bassFee;
    // 초과 시간
    int overtime = minutes - baseTime;

    // 초과 시간일 경우
    if (overtime > 0) {
        total += (overtime / unitTime) * unitFee;
        // 초과 시간 올림
        if (overtime % unitTime > 0) {
            total += unitFee;
        }
    }

    return total;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    // (차량번호, 시간)
    map<string, string> parkingIn;
    // (차량번호, 사용시간)
    map<string, int> totalTimeByCarNum;

    for (string record : records) {
        vector<string> v = splitRecord(record, " ");

        string hhmm = v[0];
        string carNum = v[1];
        string status = v[2];

        // 출차일 경우
        if (status == "OUT") {
            // 출차 시간 - 입차 시간
            int minutes = convertTimeToMinutes(hhmm) - convertTimeToMinutes(parkingIn[carNum]);
            // 차량 번호에 따라 사용시간 저장
            totalTimeByCarNum[carNum] += minutes;
            // 입차 기록 제거
            parkingIn.erase(carNum);
        } else {  // 입차일 경우
            // 차량번호에 따른 입차시간 저장
            parkingIn[carNum] = hhmm;
        }
    }

    // 입차 기록만 있는 차량 요금처리
    for (auto p : parkingIn) {
        // 출차 시간 - 입차 시간
        int minutes = convertTimeToMinutes("23:59") - convertTimeToMinutes(p.second);
        // 차 번호에 따라 주차 요금 저장
        totalTimeByCarNum[p.first] += minutes;
    }

    // 차량번호에 따른 최종 요금 반환
    for (auto info : totalTimeByCarNum) {
        answer.push_back(caculateParkingFee(fees, info.second));
    }

    return answer;
}