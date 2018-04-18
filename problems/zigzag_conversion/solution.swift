class Solution {
func convert(_ s: String, _ numRows: Int) -> String {
    var i = 0
    let ch = Array(s)
    
    var buckets: [[Character]] = Array(repeating: [Character](), count: numRows)
    
    while(i < s.count) {
        for di in 0..<numRows where i < s.count{
            buckets[di].append(ch[i])
            i += 1
        }
        
        if (numRows <= 2) {
            continue
        }
        for di in (1...(numRows - 2)).reversed() where i < s.count {
            buckets[di].append(ch[i])
            i += 1
        }
    }
    return String(buckets.flatMap{$0})
}
}