import Foundation

// 배열의 크기
let N = Int(readLine()!)!
// 배열에서 구할 K 번째 수
let K = Int(readLine()!)!
// 시작 값
var start = 1
// 마지막 값
var end = N * N

while start <= end {
    // 중간 값
    let mid = (start + end) / 2
    // 배열에서 중간 값보다 작거나 같은 값의 개수
    var count = 0
    
    for i in 1...N {
        count += min(mid / i, N)
    }
    // 중간 값보다 작거나 같은 값의 개수가 K개 이상일 경우
    if K <= count { end = mid - 1 }
    // 중간 값보다 작거나 같은 값의 개수가 K개 미만일 경우
    else { start = mid + 1 }
}

// 정답 출력
print(start)
