import Foundation

let HW = readLine()!.split(separator: " ").map { Int($0)! }
let H = HW[0]
let W = HW[1]

var sky = [String]()
var result = Array(repeating: Array(repeating: -1, count: W), count: H)

for _ in 0..<H {
    sky.append(readLine()!)
}

for i in 0..<H {
    for s in sky[i].enumerated() {
        if s.element == "c" {
            for j in s.offset..<W {
                result[i][j] = j - s.offset
            }
        }
    }
}

for i in 0..<H {
    print(result[i].map { String($0) }.joined(separator: " "))
}