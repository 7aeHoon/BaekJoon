import Foundation

// N개의 수
let N: Int = Int(readLine()!)!

// N개의 수를 가지는 오름차순 배열
// 투 포인터는 정렬이 필요
let arr: [Int] = readLine()!.split(separator: " ").map { Int($0)! }.sorted()

// 좋은 수의 개수
var result: Int = 0

for i in 0..<N {
    // 왼쪽 포인터 l, 오른쪽 포인터 r
    var l = 0
    var r = N - 1
    
    while l < r {
        if arr[l] + arr[r] < arr[i] {
            l += 1
        } else if arr[l] + arr[r] > arr[i] {
            r -= 1
        } else {
            if l != i && r != i {
                result += 1
                break
            }
            if l == i { l += 1 }
            if r == i { r -= 1 }
        }
    }
}

print(result)