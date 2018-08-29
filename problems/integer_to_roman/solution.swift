class Solution {
    func intToRoman(_ num: Int) -> String {
  assert(num != 0, "num cannot be 0")
  var result = String()
  var map = [1:"I", 4:"IV", 5:"V", 9:"IX", 10:"X", 40:"XL", 50:"L", 90:"XC", 100:"C", 400:"CD", 500:"D", 900:"CM", 1000:"M"]
  
  if let num = map[num] {
    return num
  }
  
  func processUnits() {
    let units = num % 10
    if let units = map[units] {
      result += units
      return
    }
    
    if units != 0 {
      if units < 5 {
        for _ in 0..<units {
          result += map[1]!
        }
      }
      
      if units > 5 {
        result += map[5]!
        for _ in 0..<(units - 5) {
          result += map[1]!
        }
      }
    }
  }
  
  func processTens() {
    let tens = ((num / 10) * 10) % 100
    if let tens = map[tens] {
      result = tens + result
      return
    }
    
    if tens < 50 {
      for _ in 0..<(tens / 10) {
        result = map[10]! + result
      }
    }
    
    if tens > 50 {
      var temp = map[50]!
      for _ in 0..<(tens - 50) / 10 {
        temp += map[10]!
      }
      result = temp + result
    }
  }
  
  func processHundreds() {
    let hundreds = ((num / 100) * 100) % 1000
    if let hundreds = map[hundreds] {
      result = hundreds + result
      return
    }
    
    if hundreds < 500 {
      for _ in 0..<(hundreds / 100) {
        result = map[100]! + result
      }
    }
    
    if hundreds > 500 {
      var temp = map[500]!
      for _ in 0..<(hundreds - 500) / 100 {
        temp += map[100]!
      }
      result = temp + result
    }
  }
  
  func processThousands() {
    let thousands = ((num / 1000) * 1000) % 10000
    if let thousands = map[thousands] {
      result = thousands + result
      return
    }
    
    if thousands < 4000 {
      for _ in 0..<(thousands / 1000) {
        result = map[1000]! + result
      }
    }
  }
  
  processUnits()
  processTens()
  processHundreds()
  processThousands()
  return result
}
}