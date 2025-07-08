import Foundation

func oper(a: Int, b: Int, op: Character) -> Int {
    if op == "+" { return a + b }
    else if op == "-" { return a - b }
    else { return a * b }
}

func go(index: Int, number: Int) {
    if index == numbers.count - 1 {
        answer = max(answer, number)
        return
    }
    
    go(index: index + 1, number: oper(a: number, b: numbers[index + 1], op: operators[index]))
    
    if index + 2 < numbers.count {
        let temp = oper(a: numbers[index + 1], b: numbers[index + 2], op: operators[index + 1])
        go(index: index + 2, number: oper(a: number, b: temp, op: operators[index]))
    }
    
    return
}

var operators = [Character]()
var numbers = [Int]()
var answer = Int.min

let N = Int(readLine()!)!
let str = readLine()!

for (i, ch) in str.enumerated() {
    if i % 2 == 0 { numbers.append(Int(String(ch))!) }
    else { operators.append(ch) }
}

go(index: 0, number: numbers[0])

print(answer)