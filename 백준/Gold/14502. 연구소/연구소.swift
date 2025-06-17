import Foundation

final class FileIO {
    private let buffer:[UInt8]
    private var index: Int = 0

    init(fileHandle: FileHandle = FileHandle.standardInput) {
        buffer = Array(try! fileHandle.readToEnd()!)+[UInt8(0)] // 인덱스 범위 넘어가는 것 방지
    }

    @inline(__always) private func read() -> UInt8 {
        defer { index += 1 }

        return buffer[index]
    }

    @inline(__always) func readInt() -> Int {
        var sum = 0
        var now = read()
        var isPositive = true

        while now == 10
                || now == 32 { now = read() } // 공백과 줄바꿈 무시
        if now == 45 { isPositive.toggle(); now = read() } // 음수 처리
        while now >= 48, now <= 57 {
            sum = sum * 10 + Int(now-48)
            now = read()
        }

        return sum * (isPositive ? 1:-1)
    }

    @inline(__always) func readString() -> String {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return String(bytes: Array(buffer[beginIndex..<(index-1)]), encoding: .ascii)!
    }

    @inline(__always) func readByteSequenceWithoutSpaceAndLineFeed() -> [UInt8] {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return Array(buffer[beginIndex..<(index-1)])
    }
}


func DFS(y: Int, x: Int) {
    
    visited[y][x] = 1
    
    for i in 0..<4 {
        let ny = dy[i] + y
        let nx = dx[i] + x
        
        if ny < 0 || nx < 0 || ny >= N || nx >= M {
            continue
        }
        
        if lab[ny][nx] != 0 || visited[ny][nx] == 1 {
            continue
        }
        
        DFS(y: ny, x: nx)
    }
}

func countSafeSpace() -> Int {
    var cnt = 0
    
    for i in 0..<N {
        for j in 0..<M {
            if lab[i][j] == 0 && visited[i][j] == 0 {
                cnt += 1
            }
        }
    }
    
    return cnt
}

func clearVisited() {
    for i in 0..<N {
        for j in 0..<M {
            visited[i][j] = 0
        }
    }
}

let fIO = FileIO()

let N = fIO.readInt()
let M = fIO.readInt()

var lab = Array(repeating: Array(repeating: 0, count: M) , count: N)
var visited = Array(repeating: Array(repeating: 0, count: M) , count: N)
var virusSpaces = [(Int, Int)]()
var emptySpaces = [(Int, Int)]()

let dy = [-1, 0, 1, 0]
let dx = [0, 1, 0, -1]

var result = 0

for i in 0..<N {
    for j in 0..<M {
        lab[i][j] = fIO.readInt()
        // 빈칸일 경우
        if lab[i][j] == 0 { emptySpaces.append((i, j)) }
        // 바이러스일 경우
        if lab[i][j] == 2 { virusSpaces.append((i, j)) }
    }
}

for i in 0..<emptySpaces.count {
    for j in i+1..<emptySpaces.count {
        for k in j+1..<emptySpaces.count {
            // 빈 칸 가져오기
            let first = emptySpaces[i], second = emptySpaces[j], third = emptySpaces[k]
            // 3개의 벽 생성
            lab[first.0][first.1] = 1
            lab[second.0][second.1] = 1
            lab[third.0][third.1] = 1
            
            for (y, x) in virusSpaces {
                DFS(y: y, x: x)
            }
            
            result = max(result, countSafeSpace())
            // 방문지 초기화
            clearVisited()
            // 3개의 벽 원복
            lab[first.0][first.1] = 0
            lab[second.0][second.1] = 0
            lab[third.0][third.1] = 0
        }
    }
}

print(result)