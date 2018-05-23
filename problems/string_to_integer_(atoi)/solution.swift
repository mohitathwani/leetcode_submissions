class Solution {
    enum States {
    case start, space, minus, plus, digit, alphaChar, end
}

func isNextStateValid(curState: States, nextState: States) -> Bool {
    switch curState {
    case .start:
        return nextState == .space || nextState == .minus || nextState == .digit || nextState == .plus
        
    case .space:
        return nextState == .space || nextState == .minus || nextState == .digit || nextState == .plus
        
    case .minus:
        return nextState == .digit
        
    case .plus:
        return nextState == .digit
        
    case .digit:
        return nextState == .digit
    default:
        return false
    }
}

func myAtoi(_ str: String) -> Int {
    let charArray = Array(str)
    var curState: States = .start
    
    var result = 0
    var multiplier = 1
    
    for char in charArray {
        if char == " " && isNextStateValid(curState: curState, nextState: .space){
            curState = .space
            continue
        }
        
        if char == "+" && isNextStateValid(curState: curState, nextState: .plus) {
            curState = .plus
            continue
        }
        
        if char == "-" && isNextStateValid(curState: curState, nextState: .minus) {
            curState = .minus
            multiplier = -1
            continue
        }
        
        if let digit = Int(String(char)), isNextStateValid(curState: curState, nextState: .digit) {
            curState = .digit
            result = result * 10 + digit
            
            if(result > Int32.max) {
                break
            }
        } else {
            break
        }
    }
    
    result = result * multiplier
    
    if result < Int32.min {
        return Int(Int32.min)
    }
    
    if result > Int32.max {
        return Int(Int32.max)
    }
    
    return result
}
}