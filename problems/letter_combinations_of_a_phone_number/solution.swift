class Solution {
    func letterCombinations(_ digits: String) -> [String] {
        
        if(digits.count == 0) {return []}
        let map = ["0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    
    var result = [""]
    
    for (index,value) in digits.enumerated() {
        guard let convertedDigit = Int("\(value)") else {return []}
        
        let mappedString = map[convertedDigit]
        
        while result[0].count == index {
            let dQElement = result.removeFirst()
            mappedString.forEach({ (c) in
                result.append("\(dQElement)\(c)")
            })
        }
    }
    return result
    }
}