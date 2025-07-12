import Foundation

func DFS(_ here: Int, _ depth: Int) {
    if depth == 5 {
        flag = true
        return
    }
    visited[here] = true
    for there in friends[here] {
        guard !visited[there] else { continue }
        DFS(there, depth + 1)
    }
    visited[here] = false
}


let NM = readLine()!.split(separator: " ").compactMap { Int($0) }
let N = NM[0], M = NM[1]
var friends = Array(repeating: Array<Int>(), count: N)
var visited = Array(repeating: false, count: N)
var flag = false

for _ in 0..<M {
    let ab = readLine()!.split(separator: " ").compactMap { Int($0) }
    let a = ab[0], b = ab[1]
    friends[a].append(b)
    friends[b].append(a)
}

for i in 0..<N {
    DFS(i, 1)
    if flag { break }
}

flag ? print(1) : print(0)
