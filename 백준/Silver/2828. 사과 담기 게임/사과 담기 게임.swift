import Foundation

let NM = readLine()!.split(separator: " ").map { Int($0)! }
let N = NM[0]
let M = NM[1]
let J = Int(readLine()!)!

var basketPosition: (left: Int, right: Int) = (1, M)
var result = 0

for _ in 0..<J {
    let applePosition = Int(readLine()!)!
    
    if basketPosition.left <= applePosition && applePosition <= basketPosition.right {
        continue
    }
    if applePosition < basketPosition.left {
        let moving = basketPosition.left - applePosition
        basketPosition.left -= moving
        basketPosition.right -= moving
        result += moving
    }
    if basketPosition.right < applePosition {
        let moving = applePosition - basketPosition.right
        basketPosition.left += moving
        basketPosition.right += moving
        result += moving
    }
}

print(result)