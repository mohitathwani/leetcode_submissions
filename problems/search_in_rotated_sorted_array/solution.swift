class Solution {
func search(_ nums: [Int], _ target: Int) -> Int {
  guard nums.count > 0 else {
    return -1
  }
  
  var start = 0
  var end = nums.count - 1
  
  func search(start: Int, end: Int) -> Int {
    
    if end < start {
      return -1
    }
    
    let mid = start + (end - start) / 2
    
    print(start, mid, end)
    
    if nums[mid] == target {
      return mid
    }
    
    
    //lower half is sorted
    if nums[start] <= nums[mid] {
      if target >= nums[start] && target <= nums[mid] {
        //search in lower half
        return search(start: start, end: mid - 1)
      } else {
        //search in upper half
        return search(start: mid + 1, end: end)
      }
    }
    
    //upper half is sorted
    if nums[mid] < nums[end] {
      if target >= nums[mid] && target <= nums[end] {
        //search in upper half
        return search(start: mid + 1, end: end)
      } else {
        //search in lower half
        return search(start: start, end: mid - 1)
      }
      
    }
    
    return -1
  }
  
  return search(start: 0, end: nums.count - 1)
}
}