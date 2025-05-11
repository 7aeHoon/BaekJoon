import Foundation

var meetings: [(startTime: Int, endTime: Int)] = []
var meetingCnt = 0
var beforeEndTime = 0
var index = 0

let N = Int(readLine()!)!

for _ in 0..<N {
    let meeting = readLine()!.split(separator: " ").map { Int($0)! }
    let startTime = meeting[0], endTime = meeting[1]
    meetings.append((startTime, endTime))
}

meetings.sort { ($0.endTime, $0.startTime) < ($1.endTime, $1.startTime) }

for i in 0..<N {
    let meeting = meetings[i]
    
    if beforeEndTime <= meeting.startTime {
        beforeEndTime = meeting.endTime
        meetingCnt += 1
    }
}

print(meetingCnt)