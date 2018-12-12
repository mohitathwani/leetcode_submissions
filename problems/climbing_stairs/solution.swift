class Solution {
    func climbStairs(_ n: Int) -> Int {
  var arr = [1, 1]
  
  if n == 0 || n == 1{
    return 1
  }
  
  for _ in 2...n {
    let result = arr[0] + arr[1]
    arr[0] = arr[1]
    arr[1] = result
  }
  
  return arr[1]
}
}