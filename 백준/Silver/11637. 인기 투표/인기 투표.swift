import Foundation

let T = Int(readLine()!)!

for _ in 0..<T {
    let n = Int(readLine()!)!     // 후보자 수
    var votes = [Int]()
    
    for _ in 0..<n {
        votes.append(Int(readLine()!)!)  // 한 줄씩 득표 수 읽기
    }

    let total = votes.reduce(0, +)
    guard let maxVote = votes.max() else { continue }
    let winnerCount = votes.filter { $0 == maxVote }.count
    let winnerIndex = votes.firstIndex(of: maxVote)! + 1

    if winnerCount > 1 {
        print("no winner")
    } else if maxVote * 2 > total {
        print("majority winner \(winnerIndex)")
    } else {
        print("minority winner \(winnerIndex)")
    }
}
