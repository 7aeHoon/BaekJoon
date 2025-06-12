import Foundation

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

struct IntPair: Comparable {

    let first: Int
    let second: Int
    
    static func < (lhs: IntPair, rhs: IntPair) -> Bool {
        return abs(lhs.second) != abs(rhs.second) ? abs(lhs.second) < abs(rhs.second) : lhs.first < rhs.first
    }
}

// 연산의 개수
let N = Int(readLine()!)!

// 우선순위 큐
var pq = PriorityQueue<IntPair> { $0 < $1 }
// 결과 출력 배열
var result = [Int]()

for _ in 0..<N {
    // 연산을 나타내는 정수
    let num = Int(readLine()!)!
    
    if num != 0 { // 0이 아닐 경우 원소를 추가
        pq.enqueue(IntPair(first: num, second: abs(num)))
    } else { // 0일 경우 원소를 제거
        if let pair = pq.dqeueue() { // 제거할 원소가 있을 경우
            result.append(pair.first)
        } else { // 제거할 원소가 없을 경우
            result.append(0)
        }
    }
}

// 결과 출력
for i in 0..<result.count {
    print(result[i])
}