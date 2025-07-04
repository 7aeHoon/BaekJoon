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


let N = Int(readLine()!)!
var scv = readLine()!.split(separator: " ").map { Int($0)! }

while scv.count < 3 { scv.append(0) }

let mutalisk = [
    [9, 3, 1],
    [9, 1, 3],
    [3, 9, 1],
    [3, 1, 9],
    [1, 9, 3],
    [1, 3, 9]
]

var queue = Queue<[Int]>()
var visited = Array(repeating: Array(repeating: Array(repeating: 0, count: 61), count: 61), count: 61)

visited[scv[0]][scv[1]][scv[2]] = 1
queue.push(scv)

while let front = queue.pop() {
    let x = front[0]
    let y = front[1]
    let z = front[2]
    
    if x == 0 && y == 0 && z == 0 { break }
    
    for mutal in mutalisk {
        let nx = max(0, x - mutal[0])
        let ny = max(0, y - mutal[1])
        let nz = max(0, z - mutal[2])
        if visited[nx][ny][nz] != 0 { continue }
        queue.push([nx ,ny , nz])
        visited[nx][ny][nz] = visited[x][y][z] + 1
    }
    
}

print(visited[0][0][0] - 1)
