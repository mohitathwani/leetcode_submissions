class Solution {
    func isOneEditDistance(_ s: String, _ t: String) -> Bool {
        if (s.isEmpty && t.isEmpty) || abs(s.count - t.count) > 1 || s == t {
            return false
        }
        
        let sArr = Array(s)
        let tArr = Array(t)
        
        if s.count == t.count {
            return replace(sArr, tArr)
        }
        
        if s.count < t.count {
            return insert(sArr, tArr)
        } else {
            return insert(tArr, sArr)
        }
        
        return false
    }
    
    func insert(_ s: [Character], _ t: [Character]) -> Bool {
        var i = 0
        var j = 0
        var diff = 0
        
        while i < s.count {
            if s[i] != t[j] {
                if diff == 1 {
                    return false
                }
                diff += 1
                j += 1
                continue
            }
            i += 1
            j += 1
        }
        return true
    }
    
    func replace(_ s: [Character], _ t: [Character]) -> Bool {
        var i = 0
        var diff = 0
        
        while i < s.count {
            if s[i] != t[i] {
                if diff == 1 {
                    return false
                }
                diff += 1
            }
            i += 1
        }
        return true
    }
}