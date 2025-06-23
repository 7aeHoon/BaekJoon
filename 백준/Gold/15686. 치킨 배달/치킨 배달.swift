import Foundation

// MARK: - 전역 변수
let NM = readLine()!.split(separator: " ").compactMap { Int($0) }
let N = NM[0]
let M = NM[1]

var city = Array(repeating: Array(repeating: 0, count: N), count: N)
var house = [(y: Int, x: Int)]()
var chicken = [(y: Int, x: Int)]()
var chickenList = [[Int]]()
var temp = [Int]()
var result = Int.max

// MARK: - 조합
func combi(start: Int) {
    if temp.count == M {
        chickenList.append(temp)
        return
    }
    
    for i in (start + 1)..<chicken.count {
        temp.append(i)
        combi(start: i)
        temp.removeLast()
    }
    
}

// MARK: - 메인 함수
func solution() {
    for i in 0..<N {
        let input = readLine()!.split(separator: " ").compactMap { Int($0) }
        for j in 0..<N {
            // 집일 경우
            if input[j] == 1 { house.append((i, j)) }
            // 치킨집일 경우
            if input[j] == 2 { chicken.append((i, j)) }
        }
    }
    
    combi(start: -1)
    
    for cl in chickenList {
        var cityChickenDistance = 0
        for h in house {
            var chickenDistance = Int.max
            for index in cl {
                let distance = abs(chicken[index].y - h.y)  + abs(chicken[index].x - h.x)
                chickenDistance = min(chickenDistance, distance)
            }
            cityChickenDistance += chickenDistance
        }
        result = min(result, cityChickenDistance)
    }
    
    print(result)
}

// MARK: - 시작
solution()
