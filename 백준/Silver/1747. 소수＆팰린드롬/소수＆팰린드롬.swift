import Foundation

let N: Int = Int(readLine()!)!
var isPrime: [Bool] = Array<Bool>(repeating: true, count: 1003002)

isPrime[0] = false
isPrime[1] = false

for i in 2..<1003002  {
    
    // 소수가 아닐 경우
    if !isPrime[i] { continue }
    
    for j in stride(from: i * 2, to: 1003002, by: i) {
        isPrime[j] = false
    }
    
}

for i in N..<1003002 {
    // 소수가 아닐 경우
    if !isPrime[i] { continue }
    
    let str = String(i)
    
    // 원본 문자열과 뒤집은 문자열과 같을 경우(=팰린드롬)
    if str == String(str.reversed()) {
        print(i)
        break
    }
}
