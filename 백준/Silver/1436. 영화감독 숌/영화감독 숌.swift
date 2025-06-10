import Foundation

// MARK: - 함수
func isDevilNumber(_ num: Int) -> Bool {
    var temp = num
    
    while 666 <= temp {
        if temp % 1000 == 666 {
            return true
        }
        temp /= 10
    }
    
    return false
}

// MARK: - 변수
// N 번째 영화
let N = Int(readLine()!)!
var num = 665
var cnt = 0

// MARK: - 메인
while cnt != N {
    
    if isDevilNumber(num) {
        cnt += 1
    }
    
    num += 1
}

print(num - 1)