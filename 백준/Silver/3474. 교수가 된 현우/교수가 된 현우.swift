import Foundation

// 테스트 케이스
let T = Int(readLine()!)!

for _ in 0..<T {
    let N = Int(readLine()!)!

    var val = 5
    // 5의 수 카운트
    var fiveCnt = 0
    
    while N >= val {
        // 몫 계산 후 카운트에 증가
        fiveCnt += N / val
        // 5의 제곱수만큼 증가
        val *= 5
    }
    
    print(fiveCnt)
}