import Foundation

let N = Int(readLine()!)!
var queue = [Int]()

while true {
    guard let line = readLine(), let x = Int(line) else { break }
    if x == -1 {
        // 입력 종료
        break
    } else if x == 0 {
        // 패킷 처리: dequeue
        if !queue.isEmpty {
            queue.removeFirst()
        }
    } else {
        // 새로운 패킷 도착: enqueue (공간이 남아 있을 때만)
        if queue.count < N {
            queue.append(x)
        }
    }
}

if queue.isEmpty {
    print("empty")
} else {
    // 남은 패킷을 공백으로 구분해 한 줄로 출력
    print(queue.map(String.init).joined(separator: " "))
}
