import Foundation

let firstLine = readLine()!.split(separator: " ").map { Int($0)! }
let H = firstLine[0], W = firstLine[1]

var grid = [String]()
for _ in 0..<H {
    grid.append(readLine()!)
}

var ans = Array(repeating: Array(repeating: -1, count: W), count: H)

for i in 0..<H {
    var currentTime = -1
    let row = Array(grid[i])
    for j in 0..<W {
        if row[j] == "c" {
            ans[i][j] = 0
            currentTime = 0
        } else {
            if currentTime >= 0 {
                currentTime += 1
                ans[i][j] = currentTime
            }
        }
    }
}

for i in 0..<H {
    let line = ans[i].map { String($0) }.joined(separator: " ")
    print(line)
}
