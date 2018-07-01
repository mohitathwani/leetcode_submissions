class Solution {
func lemonadeChange(_ bills: [Int]) -> Bool {
  var map = [Int:Int]()
  
  if bills[0] != 5 {
    return false
  }
  
  for bill in bills {
    if map[bill] == nil {
      map[bill] = 1
    } else {
      map[bill] = 1 + map[bill]!
    }
    
    let changeDue = bill - 5
    
    switch changeDue {
    case 0:
      continue
      
    case 5:
      if map[5] != nil && map[5]! >= 1 {
        map[5] = map[5]! - 1
        continue
      } else {
        return false
      }
      
    case 15:
      if  map[10] != nil && map[10]! >= 1 && map[5] != nil && map[5]! >= 1{
        map[10] = map[10]! - 1
        map[5] = map[5]! - 1
      }
      else if map[5] != nil && map[5]! >= 3 {
        map[5] = map[5]! - 3
      } else {
        return false
      }
    default:
      fatalError()
    }
  }
    return true
}

}