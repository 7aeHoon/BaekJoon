import Foundation

let input: [Int] = readLine()!.split(separator: " ").map { Int($0)! }
let M = input[0], N = input[1]

var arr: [Int] = Array(repeating: 0, count: N + 1)

for i in 2...N {
    if arr[i] == 1 { continue }
    
    var j = i * 2
    
    while j <= N {
        arr[j] = 1
        j += i
    }
    
}

for i in M...N {
    if i == 1 { continue }
    
    if arr[i] == 0 { print(i) }
}
