class Solution {
func minPathSum(_ grid: [[Int]]) -> Int {
  var result = 0
  
  guard !grid.isEmpty else {
    return result
  }
  
  let numRows = grid.count
  let numCols = grid[0].count
  
  var dp = [[Int]](repeating: [Int](repeating: 0, count: numCols), count: numRows)
  
  for i in stride(from: numRows - 1, through: 0, by: -1) {
    for j in stride(from: numCols - 1, through: 0, by: -1) {
      
      if i + 1 < numRows && j + 1 < numCols {
        dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1])
      }
      else if i + 1 < numRows {
        dp[i][j] = grid[i][j] + dp[i + 1][j]
      }
      else if j + 1 < numCols {
        dp[i][j] = grid[i][j] + dp[i][j + 1]
      }
      else {
        dp[i][j] = grid[i][j]
      }
    }
  }
  
  result = dp[0][0]
  
  return result
}
}