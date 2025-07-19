import Foundation

let NM = readLine()!.split(separator: " ").compactMap { Int($0) }
// 강의의 수
let N = NM[0]
// 블루레이의 수
let M = NM[1]
// 강토의 기타 강의 길이 배열
let bluRay = readLine()!.split(separator: " ").compactMap { Int($0) }
// 블루레이에 비디오를 담을 수 있는 최소 길이
var minRecord = bluRay.max()!
// 블루레이에 비디오를 담을 수 있는 최대 길이
var maxRecord = bluRay.reduce(0, +)
// 가능한 블루레이의 크기(정답)
var answer = 0
// 가능한 블루레이 크기가 나올 때까지 반복
while minRecord <= maxRecord {
    // 블루레이 중간 길이 설정
    let midRecord = (minRecord + maxRecord) / 2
    // 필요한 블루레이 수
    var cnt = 1
    // 누적된 영상의 길이
    var sum = 0
    // 몇 개의 블루레이가 필요한지 계산
    for length in bluRay {
        if sum + length <= midRecord {
            sum += length
        } else {
            cnt += 1
            sum = length
        }
    }
    // 블루레이 수가 남을 경우(낭비) 줄일 필요가 있음
    if cnt <= M {
        maxRecord = midRecord - 1
        answer = midRecord
    }
    // 블루레이 수가 모자랄 경우(부족) 늘릴 필요가 있음
    else  {
        minRecord = midRecord + 1
    }
}
// 가능한 블루레이 수 출력
print(answer)
