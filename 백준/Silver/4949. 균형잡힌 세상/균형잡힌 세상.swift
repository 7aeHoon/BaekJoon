import Foundation

while true {
    let str = readLine()!
    // 균형잡인 세상인지 판단
    var isBalancedWorld = true
    // 스택은 "(" 또는 "[" 만 저장
    var stack = [Character]()
    // 온점 하나가 나올 때 종료
    if str == "." {
        break
    }
    
    for ch in str {
        if ch == ")" {
            if stack.isEmpty || stack.last! == "[" {
                isBalancedWorld = false
                break
            }
            stack.removeLast()
        }
        
        if ch == "]" {
            if stack.isEmpty || stack.last! == "(" {
                isBalancedWorld = false
                break
            }
            stack.removeLast()
        }
        
        // 스택에 괄호 추가
        if ch == "(" || ch == "[" {
            stack.append(ch)
        }
    }
    
    // 균형잡인 세상이고 스택이 비어있을 경우
    if isBalancedWorld && stack.isEmpty {
        print("yes")
    } else {
        print("no")
    }
}