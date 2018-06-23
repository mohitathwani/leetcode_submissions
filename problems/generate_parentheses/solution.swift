class Solution {
    func generateParenthesis(_ n: Int) -> [String] {
          var result = [String]()
  var s: String = ""
  
  func backtrack(numOpen:Int = 0, numClose: Int = 0) {
    if s.count == 2 * n {
      result.append(s)
      return
    }
    
    if numOpen < n {
      s.append("(")
      backtrack(numOpen: numOpen + 1, numClose: numClose)
      s.removeLast()
    }
    
    if numClose < numOpen {
      s.append(")")
      backtrack(numOpen: numOpen, numClose: numClose + 1)
      s.removeLast()
    }
  }
  
  backtrack()
  return result

    }
}