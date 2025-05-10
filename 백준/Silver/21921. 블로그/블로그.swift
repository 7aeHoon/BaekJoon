import Foundation

let input1 = readLine()!.split(separator: " ").map { Int($0)! }

let N = input1[0]
let X = input1[1]

var arr = readLine()!.split(separator: " ").map { Int($0)! }
arr.insert(0, at: 0)

var pSum = Array(repeating: 0, count: N + 1)

var cnt = 0
var maxVisitors = 0

for i in 1...N {
    pSum[i] = pSum[i - 1] + arr[i]
}

for i in X...N {
    let visitors = pSum[i] - pSum[i - X]
    
    if maxVisitors < visitors {
        maxVisitors = visitors
        cnt = 1
    } else if maxVisitors == visitors {
        cnt += 1
    }
}

maxVisitors == 0 ? print("SAD") : print("\(maxVisitors)\n\(cnt)")