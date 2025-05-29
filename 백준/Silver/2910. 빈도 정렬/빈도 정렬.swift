import Foundation

var dic = Dictionary<Int, (Int, Int)>()

let NC = readLine()!.split(separator: " ").compactMap { Int($0) }
let N = NC[0]
let C = NC[1]

let arr = readLine()!.split(separator: " ").compactMap { Int($0) }
var result = ""

for (index, value) in arr.enumerated() {
    dic[value, default: (0, index)].0 += 1
}

let sortedDic = dic.sorted {
    return $0.value.0 != $1.value.0 ? $0.value.0 > $1.value.0 : $0.value.1 < $1.value.1
}


sortedDic.forEach {
    for _ in 0..<$0.value.0 {
        result += String($0.key) + " "
    }
}

result.removeLast()
print(result)