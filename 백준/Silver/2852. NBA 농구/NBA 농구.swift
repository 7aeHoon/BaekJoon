import Foundation

// MARK: - 함수
func toSecond(_ input: String) -> Int {
    let time = input.split(separator: ":").map { Int($0)! }
    return time[0] * 60 + time[1]
}

func toTime(_ input: Int) -> String {
    return "00\(input / 60)".suffix(2) + ":" + "00\(input % 60)".suffix(2)
}

// MARK: - 변수
// 골이 들어간 횟수
let N = Int(readLine()!)!

// 1번 팀 득점
var teamOne: (score: Int, time: Int) = (0, 0)
// 2번 팀 득점
var teamTwo: (score: Int, time: Int) = (0, 0)
var lead = [String]()


// MARK: - 메인
for _ in 0..<N {
    let record = readLine()!.split(separator: " ").map { String($0) }
    let team = record[0]
    let time = record[1]
    
    if team == "1" {
        teamOne.score += 1
    } else {
        teamTwo.score += 1
    }
    
    if teamOne.score != teamTwo.score {
        if lead.isEmpty {
            lead = record
        }
    } else {
        if lead[0] == "1" {
            teamOne.time += (toSecond(time) - toSecond(lead[1]))
        } else {
            teamTwo.time += (toSecond(time) - toSecond(lead[1]))
        }
        lead.removeAll()
    }
}

if !lead.isEmpty {
    if lead[0] == "1" {
        teamOne.time += (toSecond("48:00") - toSecond(lead[1]))
    } else {
        teamTwo.time += (toSecond("48:00") - toSecond(lead[1]))
    }
}

print(toTime(teamOne.time))
print(toTime(teamTwo.time))