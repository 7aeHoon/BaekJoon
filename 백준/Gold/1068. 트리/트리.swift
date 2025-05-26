import Foundation

func DFS(_ here: Int) {
    var childCnt = 0
    
    visited[here] = true
    
    for there in adj[here] {
        if visited[there] || deleteNode == there { continue }
        childCnt += 1
        DFS(there)
    }
    
    if childCnt == 0 { totalLeafNode += 1 }
    
}

// 트리의 노드의 개수
let N = Int(readLine()!)!
// 각 노드의 부모노드
let parentNode = readLine()!.split(separator: " ").map { Int($0)! }
// 삭제할 노드
let deleteNode = Int(readLine()!)!
// 인접 리스트
var adj = Array<[Int]>(repeating: Array<Int>(), count: N)
var visited = Array(repeating: false, count: N)

// 루트 노드
var rootNode = 0
// 전체 리프 노드 수
var totalLeafNode = 0


for (here, there) in parentNode.enumerated() {
    // -1일 경우 해당 노드는 루트 노드
    if there == -1 {
        rootNode = here
    } else {
        adj[here].append(there)
        adj[there].append(here)
    }
}

// 루트 노드를 삭제할 때
if deleteNode == rootNode {
    print(0)
    exit(0)
}

DFS(rootNode)

print(totalLeafNode)