import Foundation

// 입력
let input = readLine()!.split(separator: " ").map { Int($0)! }
// N개의 동전 가치
let N = input[0]
// 동전을 적절히 사용해서 가치의 합을 K로 만들기
var K = input[1]
// N개의 동전 배열
var coins: [Int] = []
// 결과
var result: Int = 0

// N개의 동전 가치 입력
for i in 0..<N {
    coins.append(Int(readLine()!)!)
}

// 가치가 큰 동전부터
for coin in coins.reversed() {
    // 동전으로 나눌 때 몫이 존재할 경우
    guard K / coin > 0 else { continue }
    // 필요한 동전 개수 추가
    result += K / coin
    // 나눈 후 합 갱신
    K %= coin
}

// 결과 출력
print(result)
