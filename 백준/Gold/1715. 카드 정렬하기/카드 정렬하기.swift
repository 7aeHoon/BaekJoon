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

// MARK: - 우선순위 큐 ADT
struct PriorityQueue<T: Comparable> {
    private var heap: Heap<T>
    
    init(priority: @escaping (T, T) -> Bool) {
        heap = Heap(priority: priority)
    }
    
    var count: Int { return heap.count }
    
    var isEmpty: Bool { return heap.isEmpty }
    
    var peek: T? { return heap.peek }
    
    mutating func enqueue(_ element: T) {
        heap.insert(element)
    }
    
    @discardableResult
    mutating func dqeueue() -> T? {
        return heap.remove()
    }
    
}

// MARK: - 힙 구현체
struct Heap<T: Comparable> {
    private var elements: [T] = []
    // 우선순위 (최대 힙 또는 최소 힙)
    private let priority: (T, T) -> Bool
    
    // MARK: - 힙 초기화
    init(elements: [T] = [], priority: @escaping (T, T) -> Bool) {
        self.elements = elements
        self.priority = priority
        self.buildHeap()
    }
    
    // 힙이 비어있는지 확인
    var isEmpty: Bool { return elements.isEmpty }
    // 힙의 노드 개수 조회
    var count: Int { return elements.count }
    // 힙의 루트 노드 조회
    var peek: T? { return elements.first }
    
    // MARK: - 힙을 구성시키는 메서드
    private mutating func buildHeap() {
        for index in (0..<(elements.count / 2)).reversed() {
            shiftDown(from: index)
        }
    }
    
    // MARK: - 상향식 연산(from 자식 노드 to 부모 노드), 노드 삽입 시
    private mutating func shiftUp(from index: Int) {
        // 자식 노드 인덱스
        var child = index
        // 부모 노드 인덱스
        var parent = (child - 1) / 2
        
        // 자식 노드가 루트 노드가 아니고, 자식 노드와 부모 노드를 우선순위에 따라 비교
        while child > 0 && priority(elements[child], elements[parent]) {
            elements.swapAt(child, parent)
            child = parent
            parent = (child - 1) / 2
        }
    }
    
    // MARK: - 하향식 연산(from 부모 노드 to 자식 노드), 노드 삭제 시
    private mutating func shiftDown(from index: Int) {
        var parent = index
        let count = elements.count
        
        while true {
            // 왼쪽 자식 노드 인덱스
            let left = parent * 2 + 1
            // 오른쪽 자식 노드 인덱스
            let right = left + 1
            var candidate = parent
            
            // 유효한 인덱스 범위 내 왼쪽 자식 노드와 부모 노드를 우선순위에 따라 비교
            if left < count && priority(elements[left], elements[candidate]) {
                candidate = left
            }
            if right < count && priority(elements[right], elements[candidate]) {
                candidate = right
            }
            
            // 변화가 없었을 경우 루프 종료
            guard candidate != parent else { break }
            elements.swapAt(parent, candidate)
            parent = candidate
        }
    }
    
    // MARK: - 힙에 새로운 노드를 삽입하는 메서드
    mutating func insert(_ value: T) {
        elements.append(value)
        shiftUp(from: elements.count - 1)
    }
    
    // MARK: - 힙의 루트 노드를 삭제하는 메서드
    @discardableResult
    mutating func remove() -> T? {
        guard !elements.isEmpty else { return nil }
        
        if elements.count == 1 { return elements.removeFirst() }
        
        let root = elements[0]
        elements[0] = elements.removeLast()
        shiftDown(from: 0)
        return root
    }
}


let FIO = FileIO()
let N = FIO.readInt()
var pq = PriorityQueue<Int>(priority: <)
var answer = 0

for _ in 0..<N {
    let num = FIO.readInt()
    pq.enqueue(num)
}

while pq.count > 1 {
    let first = pq.dqeueue()!
    let second = pq.dqeueue()!
    answer += (first + second)
    pq.enqueue(first + second)
}

print(answer)