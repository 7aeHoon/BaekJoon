import Foundation

func DFS(_ currentNode: Int, _ totalCost: Int) {
    visited[currentNode] = true
    
    if answer < totalCost {
        answer = totalCost
        tempNode = currentNode
    }
    
    for nextNode in list[currentNode] {
        if !visited[nextNode.0] {
            DFS(nextNode.0, nextNode.1 + totalCost)
        }
    }
}

func clear() {
    visited = [Bool](repeating: false, count: V + 1)
    answer = 0
}

let V = Int(readLine()!)! // 정점의 개수
var list = [[(Int, Int)]](repeating: [(Int, Int)](), count: V + 1)
var visited = [Bool](repeating: false, count: V + 1)
var tempNode = 0
var answer = 0

for _ in 0..<V {
    let input = readLine()!.split(separator: " ").compactMap { Int($0) }
    let startNode = input[0]
    var index = 1
    while input[index] != -1 {
        let endNode = input[index]
        let cost = input[index + 1]
        list[startNode].append((endNode, cost))
        index += 2
    }
}

DFS(1, 0)
clear()
DFS(tempNode, 0)
print(answer)
