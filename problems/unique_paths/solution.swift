class Solution {
    func uniquePaths(_ i: Int, _ j: Int) -> Int {
          guard i > 0 && j > 0 else {
    return 0
  }
  
  if i == 1 || j == 1 {
    return 1
  }
  
  var arr = [[Int]](repeating: [Int](repeating: 0, count: j), count: i)
  
  for x in 1...i-1 {
    arr[x][0] = 1
  }
  
  for x in 1...j-1 {
    arr[0][x] = 1
  }
  
  for y in 1...j-1 {
    for x in 1...i-1 {
      arr[x][y] = arr[x-1][y] + arr[x][y-1]
    }
  }
  
  return arr[i - 1][j - 1]
    }
}