class Solution {
    func merge(_ intervals: [[Int]]) -> [[Int]] {
        print(intervals)
        let sorted = intervals.sorted { a, b in
            a[0] < b[0]
        }
        var s = [[Int]]()
        
        sorted.forEach { int in
            if s.isEmpty {
                s.append(int)
            } else {
                let top = s.popLast()!
                if int[0] <= top[1] && int[1] <= top[1] {
                    s.append(top)
                } else if int[0] <= top[1]{
                    s.append([top[0], int[1]])
                } else if top == int{
                    s.append(top)
                }   else {
                    s.append(top)
                    s.append(int)
                }
            }
        }
        return s
    }
}