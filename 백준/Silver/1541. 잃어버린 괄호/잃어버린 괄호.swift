import Foundation

// 변수 초기화
var sum = 0

// 입력 시작
let input: [String] = readLine()!.split(separator: "-").map { String($0) }

sum += input[0].split(separator: "+").map { Int($0)! }.reduce(0, +)

for i in 1..<input.count {
    sum -= input[i].split(separator: "+").map { Int($0)! }.reduce(0, +)
}

print(sum)