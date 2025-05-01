import Foundation

// 수의 개수 N
let N = Int(readLine()!)!
// N개의 수를 담고있는 배열
let arr = readLine()!.split(separator: " ").map { Int($0)! }

var result = 0

for i in arr {
    // 1은 소수가 아니므로 제외
    if i == 1 { continue }
    
    var flag = true
    
    for j in 2 ..< i {
        if i % j == 0 {
            flag = false
            break
        }
    }
    
    if flag { result += 1 }
    
}

print(result)
