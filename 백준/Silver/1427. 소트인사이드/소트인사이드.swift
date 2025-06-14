import Foundation

let N = readLine()!
    .map { String($0) }
    .sorted(by: >)
    .joined()

print(N)