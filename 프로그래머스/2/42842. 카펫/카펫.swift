import Foundation

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    var answer = [Int]()
    let num = Int(Double(yellow).squareRoot())
    for i in 1...num {
        if !yellow.isMultiple(of: i) { continue }
        let height = i
        let width = yellow / i
        let brownCnt = (width + 2) * 2 + (height * 2)
        if brownCnt == brown {
            answer = [width + 2, height + 2]
            break
        }
    }
    return answer
}