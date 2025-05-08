import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
// N개의 수
let N: Int = input[0]
// 합을 구해야 하는 횟수 M
let M: Int = input[1]
// 주어진 배열
let arr: [Int] = readLine()!.split(separator: " ").map { Int($0)! }

var pSum: [Int] = Array(repeating: 0, count: 100005)

pSum[0] = arr[0]

for i in 1..<N {
    pSum[i] = pSum[i-1] + arr[i]
}

for _ in 1...M {
    // 주어지는 범위
    let rangeInput: [Int] = readLine()!.split(separator: " ").map { Int($0)! }
    // i번째 수
    let i: Int = rangeInput[0] - 1
    // j번째 수
    let j: Int = rangeInput[1] - 1
    
    if i - 1 < 0 {
        print(pSum[j])
    } else {
        print(pSum[j] - pSum[i-1])
    }
    
}