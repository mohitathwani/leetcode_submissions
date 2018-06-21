class Solution {
    func maxArea(_ height: [Int]) -> Int {
  var start = 0
  var end = height.count - 1
  
  var maxArea = 0
  
  for _ in 0..<height.count {
    if start == end {
      break
    }
    
    let left = height[start]
    let right = height[end]
    
    maxArea = max(min(left, right) * (end - start), maxArea)
    if left < right {
      start += 1
    } else {
      end -= 1
    }
  }
  
  return maxArea
}
}