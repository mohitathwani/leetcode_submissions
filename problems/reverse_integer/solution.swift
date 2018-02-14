class Solution {
    func reverse(_ x: Int) -> Int {
        var num = x
    var rev = 0
    
    while num != 0 {
        let remainder = num % 10
            rev = (rev * 10) + remainder // overflow can happen here
            num = num / 10
    }
        if(rev > Int32.max || rev < Int32.min) {
            return 0
        }
    return rev
    }
}