import Foundation

func mergeSort(_ start: Int, _ end: Int) {
    if start < end {
        let mid = (start + end) / 2
        mergeSort(start, mid)
        mergeSort(mid + 1, end)
        merge(start, mid, end)
    }
}

func merge(_ start: Int, _ mid: Int, _ end: Int) {
    for i in start...end { temp[i] = arr[i] }
    var part1 = start
    var part2 = mid + 1
    var index = start
    
    while part1 <= mid && part2 <= end {
        if temp[part1] <= temp[part2] {
            arr[index] = temp[part1]
            part1 += 1
        } else {
            arr[index] = temp[part2]
            answer += part2 - index
            part2 += 1
        }
        index += 1
    }
    
    while part1 <= mid {
        arr[index] = temp[part1]
        index += 1
        part1 += 1
    }
}

let N = Int(readLine()!)!
var arr = readLine()!.split(separator: " ").map { Int($0)! }
var temp = Array(repeating: 0, count: N)
var answer = 0
mergeSort(0, N - 1)
print(answer)
