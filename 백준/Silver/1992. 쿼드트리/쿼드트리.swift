import Foundation

// MARK: - 함수
func quadTree(_ y: Int, _ x: Int, _ size: Int) -> String {
    
    if size == 1 { return arr[y][x] }
    
    var result = ""
    let first = arr[y][x]
    
    for i in y..<(y + size) {
        for j in x..<(x + size) {
            if first != arr[i][j] {
                result += "("
                result += quadTree(y, x, size / 2)
                result += quadTree(y, x + size / 2, size / 2)
                result += quadTree(y + size / 2, x, size / 2)
                result += quadTree(y + size / 2, x + size / 2, size / 2)
                result += ")"
                return result
            }
        }
    }
    
    return arr[y][x]
}


// MARK: - 변수
var arr = [[String]]()


// MARK: - 메인
let N = Int(readLine()!)!

for _ in 0..<N {
    let s = readLine()!.map { String($0) }
    arr.append(s)
}


let result = quadTree(0, 0, N)

print(result)
