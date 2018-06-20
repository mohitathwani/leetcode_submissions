extension String {
  subscript(idx: Int) -> Character {
    return self[self.index(startIndex, offsetBy: idx)]
  }
  subscript(range: Range<Int>) -> String {
    return String(self[self.index(self.startIndex, offsetBy: range.lowerBound)..<self.index(self.startIndex, offsetBy: range.upperBound)])
  }
}
class Solution {
func isMatch(_ string: String, _ pattern: String) -> Bool {
  var T = [[Bool]](repeating: [Bool](repeating: false, count: pattern.count + 1), count: string.count + 1)
  
  T[0][0] = true

  //For patterns like a*, a*b*c* etc...
  if pattern.count > 0 {
    for i in 1...pattern.count {
      if pattern[i - 1] == "*" {
        T[0][i] = T[0][i - 2]
      }
    }
  }
  
  if string.count > 0 {
    for i in 1...string.count {
      if pattern.count > 0 {
        for j in 1...pattern.count {
          if string[i - 1] == pattern[j - 1] || pattern[j - 1] == "." {
            T[i][j] = T[i - 1][j - 1];
          }
          if pattern[j - 1] == "*" {
            T[i][j] = T[i][j - 2] || (T[i - 1][j] && (string[i - 1] == pattern[j - 2] || pattern[j - 2] == "."))
          }
        }
      }
    }
  }
  
  return T[string.count][pattern.count]
  
}
}