#include <bits/stdc++.h>

using namespace std;

struct Job {
    int id;
    int request;
    int duration;
};

struct PqCompare {
    bool operator()(const Job& l, const Job& r) const {
        // 소요 시간이 짧은 작업 우선
        if (l.duration != r.duration) {
            return l.duration > r.duration;
        }

        // 요청 시각이 빠른 작업 우선
        if (l.request != r.request) {
            return l.request > r.request;
        }

        // 작업 번호가 작은 작업 우선
        return l.id > r.id;
    }
};

bool compareRequest(const Job& l, const Job& r) {
    // 작업의 요청 시각을 기준으로 오름차순
    return l.request < r.request;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 현재 시점
    int currentTime = 0;
    // 마지막 처리 작업 인덱스
    int latestJobIndex = 0;

    // 모든 작업 목록
    vector<Job> totalJobs;

    for (int i = 0; i < jobs.size(); i++) {
        totalJobs.push_back({i, jobs[i][0], jobs[i][1]});
    }

    sort(totalJobs.begin(), totalJobs.end(), compareRequest);

    // 대기 큐
    priority_queue<Job, vector<Job>, PqCompare> watingJobs;

    // 대기 큐가 비어있지 않거나 작업이 비어있지 않았을 경우
    while (latestJobIndex < totalJobs.size() || !watingJobs.empty()) {
        
        // 작업에서 대기 큐로 가져오기
        while (latestJobIndex < totalJobs.size() && totalJobs[latestJobIndex].request <= currentTime) {
            watingJobs.push(totalJobs[latestJobIndex]);
            latestJobIndex++;
        }

        // 대기 큐에서 작업을 하나 꺼내서 수행하기
        if (!watingJobs.empty()) {
            // 하드 디스크가 수행할 작업
            Job currentJob = watingJobs.top();
            watingJobs.pop();

            // 해당 작업의 소요시간만큼 현재 시간에 누적
            currentTime += currentJob.duration;
            // 반환 시간 계산
            answer += currentTime - currentJob.request;
        } else {
            // 대기 큐에 작업이 없으니, 다음 작업으로 현재 시간 이동
            currentTime = totalJobs[latestJobIndex].request;
        }
    }

    return answer / jobs.size();
}