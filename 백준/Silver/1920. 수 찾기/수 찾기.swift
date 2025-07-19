import Foundation

func binarySearch(_ arr: [Int], _ num: Int) -> Bool {
    var startIndex = 0
    var endIndex = arr.count - 1
    while startIndex <= endIndex {
        let midIndex = (startIndex + endIndex) / 2
        if arr[midIndex] < num { startIndex = midIndex + 1 }
        else if arr[midIndex] > num { endIndex = midIndex - 1 }
        else { return true }
    }
    return false
}

let N = Int(readLine()!)!
let arr = readLine()!.split(separator: " ").compactMap { Int($0) }.sorted()
let M = Int(readLine()!)!
let arr2 = readLine()!.split(separator: " ").compactMap { Int($0) }
var answers = [Int]()

for num in arr2 {
    answers.append(binarySearch(arr, num) ? 1 : 0)
}

for answer in answers {
    print(answer)
}