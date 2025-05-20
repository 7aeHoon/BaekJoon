import Foundation

// MARK: - 덱
struct Deque<T> {
    // 뒷단을 담당
    var enqueue: [T] = []
    // 앞단을 담당
    var dequeue: [T] = []
    
    // MARK: - 초기화
    init(_ enqueue: [T] = []) {
        self.enqueue = enqueue
    }
    
    // 덱의 원소 개수 조회
    var count: Int {
        return enqueue.count + dequeue.count
    }
    
    // 덱이 비어있는지 확인
    var isEmpty: Bool {
        return enqueue.isEmpty && dequeue.isEmpty
    }
    
    // 덱의 앞단 원소 조회
    var front: T? {
        return dequeue.isEmpty ? enqueue.first : dequeue.last
    }
    
    // 덱의 뒷단 원소 조회
    var back: T? {
        return enqueue.isEmpty ? dequeue.first : enqueue.last
    }
    
    // MARK: - 덱 앞단 원소 삽입
    mutating func pushFront(_ element: T) {
        dequeue.append(element)
    }
    
    // MARK: - 덱 앞단 원소 삭제
    @discardableResult
    mutating func popFront() -> T? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue.removeAll()
        }
        return dequeue.popLast()
    }
    
    // MARK: - 덱 뒷단 원소 삽입
    mutating func pushBack(_ element: T) {
        enqueue.append(element)
    }
    
    // MARK: - 덱 뒷단 원소 삭제
    @discardableResult
    mutating func popBack() -> T? {
        if enqueue.isEmpty {
            enqueue = dequeue.reversed()
            dequeue.removeAll()
        }
        return enqueue.popLast()
    }
    
    // MARK: - 덱의 모든 원소 삭제
    mutating func removeAll() {
        enqueue.removeAll()
        dequeue.removeAll()
    }
    
}


let N = Int(readLine()!)!
let balloons = readLine()!.split(separator: " ").map { Int($0)! }

var deque = Deque<(Int, Int)>()
var isFront = true
var result = ""

for balloon in balloons.enumerated() {
    deque.pushBack((balloon.offset + 1, balloon.element))
}

while !deque.isEmpty {
    let ballon: (Int, Int) = isFront ? deque.popFront()! : deque.popBack()!
    
    result += String(ballon.0) + " "
    
    isFront = ballon.1 > 0
    
    if deque.isEmpty { break }
    
    if isFront {
        for _ in 0..<(abs(ballon.1) - 1) {
            deque.pushBack(deque.popFront()!)
        }
    } else {
        for _ in 0..<(abs(ballon.1) - 1) {
            deque.pushFront(deque.popBack()!)
        }
    }
}

result.removeLast()
print(result)