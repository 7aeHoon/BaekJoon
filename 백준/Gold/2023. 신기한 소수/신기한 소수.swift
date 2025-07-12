import Foundation

func isPrime(_ num: Int) -> Bool {
    for i in 2..<Int(sqrt(Double(num))) + 1 {
        if num % i == 0 { return false }
    }
    return true
}

func DFS(_ num: Int, _ length: Int) {
    if length == N {
        if isPrime(num) { primeArr.append(num) }
        return
    }
    
    for i in [1, 3, 5, 7, 9] where isPrime(num * 10 + i)  {
        DFS(num * 10 + i, length + 1)
    }
}

let N = Int(readLine()!)!
var primeArr = [Int]()

for i in [2, 3, 5, 7] {
    DFS(i, 1)
}

for primeNum in primeArr {
    print(primeNum)
}
