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


let fIO = FileIO()
let N = fIO.readInt()
// 사이즈 N 배열
var arr = [(Int, Int)]()
// 버블 정렬 수행 카운트
var bubbleSortCnt = -N

for i in 0..<N {
    let num = fIO.readInt()
    arr.append((i, num))
}

arr.sort { $0.1 < $1.1 }

for i in 0..<N {
    // 정렬을 1회 수행할 때, 원소는 왼쪽으로 1칸씩 이동가능
    // 정렬을 1회 수행할 때, 원소는 우측으로 0칸 이상으로 움직을 수 있으므로 우측 이동으로는 정렬 카운트 계산 불가.
    // numd의 정렬 전 배열에서 인덱스 - num의 정렬 후 배열 인덱스
    bubbleSortCnt = max(bubbleSortCnt, arr[i].0 - i)
}

print(bubbleSortCnt + 1)