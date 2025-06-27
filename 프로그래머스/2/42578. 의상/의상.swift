import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var closet = [String: [String]]()
    var answer = 1
    
    for info in clothes {
        closet[info[1], default: []].append(info[0])
    }
    
    for item in closet {
        answer *= (item.value.count + 1)
    }
    
    return answer - 1
}