import Foundation

let N = Int(readLine()!)!
var arr = [Int]()

for _ in 0..<N {
    let num = Int(readLine()!)!
    arr.append(num)
}

arr.sort()

arr.forEach { print($0) }