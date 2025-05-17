import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let N = input[0]
let K = input[1]

let arr = readLine()!.split(separator: " ").map { Int($0)! }
var lions = [Int]()
var size = 1000005

for i in 0..<N {
    if arr[i] == 1 { lions.append(i) }
}

if lions.count < K {
    size = -1
} else {
    var end = K - 1
    while end < lions.count {
        let start = end - K + 1
        size = min(size, lions[end] - lions[start] + 1)
        end += 1
    }
}

print(size)