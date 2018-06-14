    extension String {
  subscript(idx: Int) -> Character {
    return self[self.index(startIndex, offsetBy: idx)]
  }
  subscript(range: Range<Int>) -> String {
    return String(self[self.index(self.startIndex, offsetBy: range.lowerBound)..<self.index(self.startIndex, offsetBy: range.upperBound)])
  }
}
class Solution {

func isMatch(_ s: String, _ p: String) -> Bool {
  
  if p.isEmpty {
    return s.isEmpty
  }
  
  let firstMatch = !s.isEmpty && (s[0] == p[0] || p[0] == ".")
  
  if p.count > 1 && p[1] == "*" {
    return firstMatch && isMatch(s[1..<s.count], p) || isMatch(s, p[2..<p.count])
  }
  return firstMatch && isMatch(s[1..<s.count], p[1..<p.count])
}
}