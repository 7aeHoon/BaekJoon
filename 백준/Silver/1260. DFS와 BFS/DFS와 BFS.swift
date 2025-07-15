import Foundation

struct Queue<T> {

    private var enqueue: [T] = []
    private var dequeue: [T] = []
    
    var size: Int {
        return enqueue.count + dequeue.count
    }
    
    var isEmpty: Bool {
        return enqueue.isEmpty && dequeue.isEmpty
    }
    
    var first: T? {
        return dequeue.isEmpty ? enqueue.first : dequeue.last
    }
    
    @discardableResult
    mutating func pop() -> T? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue.removeAll()
        }
        return dequeue.popLast()
    }
    
    mutating func push(_ element: T) {
        enqueue.append(element)
    }
    
    mutating func removeAll() {
        enqueue.removeAll()
        dequeue.removeAll()
    }
    
}


let NMV = readLine()!.split(separator: " ").compactMap { Int($0) }
let N = NMV[0]
let M = NMV[1]
let V = NMV[2]
var graph = [[Int]](repeating: [Int](), count: 1005)
var visited = [Bool](repeating: false, count: 1005)
var queue = Queue<Int>()
var result = [String]()

func DFS(_ here: Int) {
    if visited[here] { return }
    visited[here] = true
    result.append("\(here)")
    for there in graph[here] where !visited[there] {
        DFS(there)
    }
}

func BFS() {
    while !queue.isEmpty, let here = queue.pop() {
        result.append("\(here)")
        for there in graph[here] where !visited[there] {
            visited[there] = true
            queue.push(there)
        }
    }
}

func clear() {
    visited = [Bool](repeating: false, count: 1005)
    result = []
}

func solution() {
    for _ in 0..<M {
        let input = readLine()!.split(separator: " ").compactMap { Int($0) }
        graph[input[0]].append(input[1])
        graph[input[1]].append(input[0])
    }
    
    for i in 1...N { graph[i].sort() }
    
    
    DFS(V)
    print(result.joined(separator: " "))
    
    clear()
    
    queue.push(V)
    visited[V] = true
    BFS()
    print(result.joined(separator: " "))
}

solution()
