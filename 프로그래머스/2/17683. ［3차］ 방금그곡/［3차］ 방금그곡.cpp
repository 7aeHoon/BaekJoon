#include <bits/stdc++.h>

using namespace std;

// (순서, 시작 시각, 종료 시각, 재생 시간, 음악 제목, 악보 정보)
typedef tuple<int, string, string, int, string, string> Musicinfo;

int getRunningTime(string s, string e) {
    istringstream ss(s);
    istringstream es(e);

    string hour, minute;

    getline(ss, hour, ':');
    getline(ss, minute);

    int start = stoi(hour) * 60 + stoi(minute);

    getline(es, hour, ':');
    getline(es, minute);

    int end = stoi(hour) * 60 + stoi(minute);

    return end - start;
}

string normalize(const string& m) {
    string result;

    for (int i = 0; i < m.size(); i++) {
        char note = m[i];

        if (i + 1 < m.size() && m[i + 1] == '#') {
            note = tolower(note);
            i++;
        }

        result.push_back(note);
    }

    return result;
}

vector<Musicinfo> parse(const vector<string>& musicinfos) {
    vector<Musicinfo> result;

    for (int i = 0; i < musicinfos.size(); i++) {
        string info = musicinfos[i];

        istringstream ss(info);

        string startTime, endTime, title, melody;

        getline(ss, startTime, ',');
        getline(ss, endTime, ',');
        getline(ss, title, ',');
        getline(ss, melody);

        int runningTime = getRunningTime(startTime, endTime);

        result.push_back({i, startTime, endTime, runningTime, title, melody});
    }

    return result;
}

bool compare(Musicinfo l, Musicinfo r) {
    if (get<3>(l) != get<3>(r)) {
        return get<3>(l) > get<3>(r);
    }
    return get<0>(l) < get<0>(r);
}

string solution(string m, vector<string> musicinfos) {
    vector<Musicinfo> infos = parse(musicinfos);

    sort(infos.begin(), infos.end(), compare);

    string normalizedM = normalize(m);

    for (const Musicinfo& info : infos) {
        int runningTime = get<3>(info);
        string melody = normalize(get<5>(info));
        string totalMelody;

        for (int i = 0; i < runningTime; i++) {
            totalMelody += melody[i % melody.size()];
        }
        
        if (totalMelody.find(normalizedM) != string::npos) {
            return get<4>(info);
        }
    }

    return "(None)";
}