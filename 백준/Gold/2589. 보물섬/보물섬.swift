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

let HW = readLine()!.split(separator: " ").compactMap { Int($0) }
let height = HW[0]
let width = HW[1]
var island = [[String]]()
var visited = Array(repeating: Array(repeating: 0, count: width), count: height)
let directions: [(y: Int, x: Int)] = [(-1, 0), (0, 1), (1, 0), (0, -1)]
var time = 0
var answer = 0

// MARK: - 메인 함수
func solution() {
    
    for _ in 0..<height {
        let input = readLine()!.map { String($0) }
        island.append(input)
    }
    
    for i in 0..<height {
        for j in 0..<width {
            guard island[i][j] == "L" else { continue }
            visited[i][j] = 1
            BFS(start: (i, j))
            reset()
        }
    }
    
    
    print(answer - 1)
}

func BFS(start: (y: Int, x: Int)) {
    var queue = Queue<(y: Int, x: Int)>()
    queue.push(start)

    while let current = queue.pop() {
        for dir in directions {
            let ny = current.y + dir.y
            let nx = current.x + dir.x
            if ny < 0 || ny >= height || nx < 0 || nx >= width { continue }
            if island[ny][nx] == "W" || visited[ny][nx] != 0 { continue }
            queue.push((ny, nx))
            visited[ny][nx] = visited[current.y][current.x] + 1
            time = max(time, visited[ny][nx])
        }
    }
    
    answer = max(answer, time)
}

func reset() {
    visited = Array(repeating: Array(repeating: 0, count: width), count: height)
    time = 0
}

// MARK: - 시작
solution()
