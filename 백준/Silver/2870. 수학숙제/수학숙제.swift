import Foundation

func dropZeroCharacters(_ str: String) -> String {
    let drop = str.drop { $0 == "0" }
    return !drop.isEmpty ? drop.description : "0"
}


let N = Int(readLine()!)!
var arr = Array<String>()

for _ in 0..<N {
    
    let str = readLine()!.map { String($0) }
    var temp = ""
    
    str.forEach {
        if Int($0) != nil {
           temp += $0
        } else {
            if !temp.isEmpty {
                let trim = dropZeroCharacters(temp)
                arr.append(trim)
                temp = ""
            }
        }
    }
    
    if !temp.isEmpty {
        let trim = dropZeroCharacters(temp)
        arr.append(trim)
    }
    
}

arr.sorted { ($0.count != $1.count) ? $0.count < $1.count : $0 < $1 }
    .forEach { print($0) }