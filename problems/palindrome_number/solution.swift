class Solution {
    func isPalindrome(_ x: Int) -> Bool {
  if x < 0 {
    return false
  }
  
  if x < 10 {
    return true
  }
  
  var original = x
  var reversed = 0
  
  while original != 0 {
    let remainder = original % 10
    reversed = reversed * 10 + remainder
    original = original / 10
  }
  
  return reversed == x
}
}