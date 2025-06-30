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

let RC = readLine()!.split(separator: " ").compactMap { Int($0) }
let R = RC[0], C = RC[1]
var maze = [[String]]()
var visited = Array(repeating: Array(repeating: 0, count: C), count: R)
var fireVisted = Array(repeating: Array(repeating: 0, count: C), count: R)
var jihoon = (y: 0, x: 0)
var fire = [(y: Int, x: Int)]()
var queue = Queue<(y: Int, x: Int)>()
var directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
var answer = Int.max

// MARK: - 미로 입력 받기
for _ in 0..<R {
    let input = readLine()!.map { String($0) }
    maze.append(input)
}

// MARK: - 미로에서 지훈이의 위치와 불의 위치 찾기
for i in 0..<R {
    for j in 0..<C {
        if maze[i][j] == "J" { jihoon = (i, j) }
        if maze[i][j] == "F" { fire.append((i, j)) }
    }
}

// MARK: - 초기 불의 위치
for (i, j) in fire {
    queue.push((i, j))
    visited[i][j] = 1
}

// MARK: - 불의 이동을 계산하기 위한 BFS
while !queue.isEmpty {
    let current = queue.pop()!
    for (dy, dx) in directions {
        let ny = current.y + dy
        let nx = current.x + dx
        if ny < 0 || nx < 0 || ny >= R || nx >= C { continue }
        if visited[ny][nx] != 0 || maze[ny][nx] == "#" { continue }
        queue.push((ny, nx))
        visited[ny][nx] = visited[current.y][current.x] + 1
    }
}

// MARK: - 미로에서 불의 위치 저장
for i in 0..<R {
    for j in 0..<C {
        fireVisted[i][j] = visited[i][j]
    }
}

// MARK: - 방문처리 초기화
visited = Array(repeating: Array(repeating: 0, count: C), count: R)

if jihoon.y == 0 || jihoon.y == R - 1 || jihoon.x == 0 || jihoon.x == C - 1 {
    print(1)
    exit(0)
}

queue.push(jihoon)
visited[jihoon.y][jihoon.x] = 1

// MARK: - 지훈이의 이동을 계산하기 위한 BFS
while !queue.isEmpty {
    let current = queue.pop()!
    for (dy, dx) in directions {
        let ny = current.y + dy
        let nx = current.x + dx
        if ny < 0 || nx < 0 || ny >= R || nx >= C { continue }
        if visited[ny][nx] != 0 || maze[ny][nx] == "#" { continue }
        if fireVisted[ny][nx] != 0 {
            if visited[current.y][current.x] + 1 >= fireVisted[ny][nx] { continue }
        }
        queue.push((ny, nx))
        visited[ny][nx] = visited[current.y][current.x] + 1
        if ny == 0 || nx == 0 || ny == R - 1 || nx == C - 1 { answer = min(answer, visited[ny][nx]) }
    }
}

// MARK: - 결과 출력
answer == Int.max ? print("IMPOSSIBLE") : print(answer)