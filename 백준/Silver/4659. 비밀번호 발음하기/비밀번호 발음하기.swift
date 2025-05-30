import Foundation

while true {
    // 검증할 패스워드
    let password = readLine()!
    // 모음 카운트
    var totalVowelsCount = 0
    // 모음이 등장하면 +1, 자음이 등장하면 -1
    var wordSum = 0
    // 이전 글자
    var beforeWord = ""
    
    var isAcceptable = true
    
    // "end"가 입력되면 종료
    if password == "end" { break }
    
    for word in password {
        
        // 모음이 등장했을 때
        if word == "a" || word == "e" || word == "i" || word == "o" || word == "u" {
            // 전체 모음 수 +1 증가
            totalVowelsCount += 1
            // 이전까지는 자음만 등장했을 때
            if wordSum < 0 { wordSum = 0 }
            wordSum += 1
        } else { // 자음이 등장했을 때
            // 이전까지는 모음만 등장했을 때
            if wordSum > 0 { wordSum = 0 }
            wordSum -= 1
        }
        
        // 모음이나 자음이 3개 연속으로 등장했을 때
        if wordSum == 3 || wordSum == -3 {
            // 품질이 좋지 않은 비밀번호로 판단
            isAcceptable = false
            break
        }
            
        // 이전 단어와 같은 단어가 나왔을 때
        if beforeWord == String(word) {
            // "ee"와 "oo"가 아닌 경우
            if beforeWord != "e" && beforeWord != "o" {
                // 품질이 좋지 않은 비밀번호로 판단
                isAcceptable = false
                break
            }
        }
        
        // 현재 단어를 이전 단어에 저장
        beforeWord = String(word)
    }
    
    // 모음이 하나라도 등장하지 않음
    if totalVowelsCount == 0 {
        isAcceptable = false
    }
    
    
    if isAcceptable {
        print("<\(password)> is acceptable.")
    } else {
        print("<\(password)> is not acceptable.")
    }
    
}