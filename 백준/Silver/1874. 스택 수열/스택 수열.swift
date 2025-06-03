import Foundation

let N = Int(readLine()!)!
var stack = [Int]()
var result = [String]()
var lastNum = 1


for _ in 0..<N {
    let inputNum = Int(readLine()!)!
    
    while lastNum <= inputNum {
        stack.append(lastNum)
        result.append("+")
        lastNum += 1
    }
    
    if let top = stack.last, top == inputNum {
        stack.removeLast()
        result.append("-")
    } else {
        print("NO")
        exit(0)
    }
}

print(result.joined(separator: "\n"))