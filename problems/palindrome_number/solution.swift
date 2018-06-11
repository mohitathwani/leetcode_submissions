class Solution {
func isPalindrome(_ x: Int) -> Bool {
  if x < 0 {
    return false
  }
  
  if x >= 0 && x < 10 {
    return true
  }
  
  if x % 10 == 0 {
    return false
  }
  
  var original = x
  var reversed = 0
  
  while original != 0 {
    let remainder = original % 10
    reversed = reversed * 10 + remainder
    original = original / 10
    
    if  reversed  >= original{
      return reversed == original || original == reversed / 10
    }
  }
  
  return false
}
}