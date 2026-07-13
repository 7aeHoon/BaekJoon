#include <bits/stdc++.h>

using namespace std;

bool compareGenre(const pair<string, int>& l, const pair<string, int>& r) {
    // 재생 횟수 내림차순 정렬
    return l.second > r.second;
}

bool compareSong(const pair<int, int>& l, const pair<int, int>& r) {
    // 1. 재생 횟수 내림차순
    if (l.first != r.first) return l.first > r.first;
    // 2. 고유번호 오름차순
    return l.second < r.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // 장르 전체 재생 횟수
    unordered_map<string, int> genreTotalPlays;
    // 장르 전체 노래
    unordered_map<string, vector<pair<int, int>>> genreTotalSongs;

    int N = genres.size();

    // 고유 번호 순으로 조회
    for (int i = 0; i < N; i++) {
        // 장르
        string genre = genres[i];
        // 재생 횟수
        int play = plays[i];
        // 해당 장르의 전체 횟수 누적
        genreTotalPlays[genre] += play;
        // 해당 장르에 곡 추가, {재생 수, 고유 번호}
        genreTotalSongs[genre].push_back({play, i});
    }

    //
    vector<pair<string, int>> v;

    // 맵의 원소를 벡터에 넣기
    for (const auto& p : genreTotalPlays) {
        v.push_back({p.first, p.second});
    }

    // 장르의 전체 재생 횟수 기준 내림차순 정렬
    sort(v.begin(), v.end(), compareGenre);

    // 벡터 순차 조회
    for (const auto& p : v) {
        string genre = p.first;
        // 해당 장르에 속한 전체 곡
        vector<pair<int, int>> songs = genreTotalSongs[genre];

        sort(songs.begin(), songs.end(), compareSong);

        // 베스트 앨범에 들어갈 첫 번째 곡
        answer.push_back(songs[0].second);

        if (songs.size() >= 2) {
            // 베스트 앨범에 들어갈 두 번째 곡
            answer.push_back(songs[1].second);
        }
    }

    return answer;
}