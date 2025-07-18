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


let NM = readLine()!.split(separator: " ").compactMap { Int($0) }
let N = NM[0]
let M = NM[1]
var maze = Array(repeating: Array(repeating: 0, count: 105), count: 105)
var visited = Array(repeating: Array(repeating: 0, count: 105), count: 105)
let directions: [(y: Int, x: Int)] = [(-1, 0), (0, 1), (1, 0), (0, -1)]
var queue = Queue<(y: Int, x: Int)>()

func BFS() {
    while let current = queue.pop() {
        let y = current.y
        let x = current.x
        for dir in directions {
            let ny = y + dir.y
            let nx = x + dir.x
            if ny < 0 || nx < 0 || ny >= N || nx >= M || maze[ny][nx] == 0 { continue }
            if visited[ny][nx] != 0 { continue }
            queue.push((ny, nx))
            visited[ny][nx] = visited[y][x] + 1
        }
    }
}

func solution() {
    for i in 0..<N {
        let row = readLine()!.map { Int(String($0))! }
        for j in 0..<M {
            maze[i][j] = row[j]
        }
    }
    queue.push((0, 0))
    visited[0][0] = 1
    BFS()
    print(visited[N - 1][M - 1])
}

solution()