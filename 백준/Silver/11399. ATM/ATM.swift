import Foundation

let N = Int(readLine()!)!
var pSum = Array(repeating: 0, count: N + 1)

var waiting = readLine()!
    .split(separator: " ")
    .compactMap { Int($0) }
    .sorted()

waiting.insert(0, at: 0)

for i in 1...N{
    pSum[i] = pSum[i-1] + waiting[i]
}

let totalWatingTime = pSum.reduce(0, +)

print(totalWatingTime)