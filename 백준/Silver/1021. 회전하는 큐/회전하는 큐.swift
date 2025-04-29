let input = readLine()!.split(separator: " ")
// 큐의 사이즈 N
let N = Int(input[0])!
// 뽑아내려고 하는 수의 개수
let M = Int(input[1])!

// 뽑아내려고 하는 수의 위치(순서대로)
let indexArr = readLine()!.split(separator: " ").map { Int($0)! }

// 큐
var queue: [Int] = Array(1...N)
// 최소 회전 수
var result = 0

for i in indexArr {
    // 뽑아낼 원소의 인덱스
    let index = queue.firstIndex(of: i)!
    
    if index <= queue.count / 2 {
        for _ in 0..<index {
            queue.append(queue.removeFirst())
            result += 1
        }
    } else {
        for _ in 0..<(queue.count - index) {
            queue.insert(queue.removeLast(), at: 0)
            result += 1
        }
    }
    // 맨 앞의 원소 제거
    queue.removeFirst()
}
// 최종 결과 출력
print(result)