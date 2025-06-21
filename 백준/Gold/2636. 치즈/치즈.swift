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

// MARK: - 전역 변수
let fIO = FileIO()
// 높이
let height = fIO.readInt()
// 너비
let width = fIO.readInt()
// 치즈 배열
var cheezeArr = Array(repeating: Array(repeating: 0, count: width), count: height)
// 방문 체크 배열
var visited = Array(repeating: Array(repeating: false, count: width), count: height)
// 이동 방향 설정
let directions: [(y: Int, x: Int)] = [(-1, 0), (0, 1), (1, 0), (0, -1)]
// 녹일 치즈의 위치 배열
var meltingCheeze = [(y: Int, x: Int)]()
// 전체 치즈 수
var totalCheeze = 0
// 녹이기 전 치즈 수
var beforeCheeze = 0
// 경과 시간
var time = 0

// MARK: - 치즈 배열 세팅
func setupCheezeArr() {
    for i in 0..<height {
        for j in 0..<width {
            let num = fIO.readInt()
            if num == 1 { totalCheeze += 1 }
            cheezeArr[i][j] = num
        }
    }
}

// MARK: - 방문 배열 초기화
func resetVisited() {
    for i in 0..<height {
        for j in 0..<width {
            visited[i][j] = false
        }
    }
}

// MARK: - 치즈 녹이기
func meltCheeze() {
    meltingCheeze.forEach { cheezeArr[$0][$1] = 0 }
    totalCheeze -= meltingCheeze.count
    meltingCheeze.removeAll()
}

// MARK: - 깊이우선탐색
func DFS(y: Int, x: Int) {
    // 방문 처리
    visited[y][x] = true
    // 다음 탐색할 공간
    for i in 0..<4 {
        let ny = y + directions[i].y
        let nx = x + directions[i].x
        // 배열의 사이즈를 벗어날 경우
        if ny < 0 || nx < 0 || ny >= height || nx >= width { continue }
        // 이미 방문했을 경우
        if visited[ny][nx] { continue }
        // 치즈가 있는 공간일 경우
        if cheezeArr[ny][nx] == 1 {
            visited[ny][nx] = true
            meltingCheeze.append((ny, nx))
            continue
        }
        DFS(y: ny, x: nx)
    }
}


// MARK: - 메인 함수
func solution() {
    setupCheezeArr()
    
    while totalCheeze > 0 {
        resetVisited()
        DFS(y: 0, x: 0)
        beforeCheeze = totalCheeze
        time += 1
        meltCheeze()
    }
    
    print(time)
    print(beforeCheeze)
}

// MARK: - 시작
solution()