import Foundation

let N = Int(readLine()!)!
// 사이즈 N 배열
var arr = [(Int, Int)]()
// 버블 정렬 수행 카운트
var bubbleSortCnt = -N

for i in 0..<N {
    let num = Int(readLine()!)!
    arr.append((i, num))
}

arr.sort { $0.1 < $1.1 }

for i in 0..<N {
    // 정렬을 1회 수행할 때, 원소는 왼쪽으로 1칸씩 이동가능
    // 정렬을 1회 수행할 때, 원소는 우측으로 0칸 이상으로 움직을 수 있으므로 우측 이동으로는 정렬 카운트 계산 불가.
    // numd의 정렬 전 배열에서 인덱스 - num의 정렬 후 배열 인덱스
    bubbleSortCnt = max(bubbleSortCnt, arr[i].0 - i)
}

print(bubbleSortCnt + 1)