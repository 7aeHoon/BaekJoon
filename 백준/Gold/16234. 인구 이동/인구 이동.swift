import Foundation

var N = 0
var L = 0
var R = 0
var city = [[Int]]()
var visited = [[Bool]]()
var arr = [(y: Int, x: Int)]()
let directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
var moved = false
var answer = 0

func DFS(_ y: Int, _ x: Int) {
    visited[y][x] = true
    arr.append((y, x))
    for (dy, dx) in directions {
        let ny = y + dy
        let nx = x + dx
        if ny < 0 || nx < 0 || ny >= N || nx >= N { continue }
        if visited[ny][nx] { continue }
        let diff = abs(city[ny][nx] - city[y][x])
        if L <= diff && diff <= R { DFS(ny, nx) }
    }
}

// MARK: - 시작
func solution() {
    let input = readLine()!.split(separator: " ").compactMap { Int($0) }
    N = input[0]
    L = input[1]
    R = input[2]
    
    for _ in 0..<N {
        let input = readLine()!.split(separator: " ").compactMap { Int($0) }
        city.append(input)
    }
    
    while true {
        visited = Array(repeating: Array(repeating: false, count: N), count: N)
        moved = false
        
        for i in 0..<N {
            for j in 0..<N where !visited[i][j] {
                arr.removeAll()
                DFS(i, j)
                if arr.count > 1 {
                    moved = true
                    let sum  = arr.reduce(0) { $0 + city[$1.y][$1.x] }
                    let avg = sum / arr.count
                    for (y, x) in arr { city[y][x] = avg }
                }
            }
        }
        guard moved else { break }
        answer += 1
    }
    
    print(answer)
}

solution()