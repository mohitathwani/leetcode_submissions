class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        var minPrice = Int.max
    var maxProfitEarned = 0
    
    for value in prices {
        if value < minPrice {
            minPrice = value
        }
        else if ((value - minPrice) > maxProfitEarned) {
            maxProfitEarned = value - minPrice
        }
    }
    
    return maxProfitEarned
    }
}