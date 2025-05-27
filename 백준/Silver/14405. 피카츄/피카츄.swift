import Foundation

// 1. 입력
let s = readLine()!

// 2. 사용할 토큰 목록
let tokens = ["pi", "ka", "chu"]

// 3. 문자열을 앞에서부터 순회하며 토큰 매칭
var idx = s.startIndex
var ok = true

while idx < s.endIndex {
    var matched = false
    for token in tokens {
        if s[idx...].hasPrefix(token) {
            // 토큰 길이만큼 인덱스 이동
            idx = s.index(idx, offsetBy: token.count)
            matched = true
            break
        }
    }
    // 어떤 토큰에도 매칭되지 않으면 실패
    if !matched {
        ok = false
        break
    }
}

// 4. 결과 출력
print(ok ? "YES" : "NO")
