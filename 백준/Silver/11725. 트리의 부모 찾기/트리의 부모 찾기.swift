import Foundation

func dfs(_ here: Int) {
    
    visited[here] = true
    
    for there in adj[here] {
        if visited[there] { continue }
        result[there] = here
        dfs(there)
    }
    
}


let N = Int(readLine()!)!

var visited = Array(repeating: false, count: N + 1)
var result = Array(repeating: 0, count: N + 1)
var adj = [[Int]](repeating: [], count: N + 1)

for _ in 1...N-1 {
    let nodes = readLine()!.split(separator: " ").map { Int($0)! }
    adj[nodes[0]].append(nodes[1])
    adj[nodes[1]].append(nodes[0])
}


dfs(1)

for i in result[2...N] {
    print(i)
}