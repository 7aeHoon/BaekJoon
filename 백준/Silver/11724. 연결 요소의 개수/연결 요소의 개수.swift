import Foundation

func DFS(_ here: Int) {
    
    visited[here] = true
    
    for there in graph[here] {
        if visited[there] { continue }
        DFS(there)
    }
    
}

let NM = readLine()!.split(separator: " ").compactMap { Int($0) }
let N = NM[0], M = NM[1]

var graph = Array(repeating: Array<Int>(), count: N + 1)
var visited = Array(repeating: false, count: N + 1)
var answer = 0

for _ in 0..<M {
    let input = readLine()!.split(separator: " ").compactMap { Int($0) }
    let u = input[0], v = input[1]
    graph[u].append(v)
    graph[v].append(u)
}

for i in 1...N {
    if visited[i] { continue }
    DFS(i)
    answer += 1
}

print(answer)