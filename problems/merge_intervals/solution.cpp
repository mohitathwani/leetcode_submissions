bool myfunction (vector<int> i, vector<int> j) { return (i[0]<j[0]); }
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> sortedIntervals = intervals;
        sort(sortedIntervals.begin(), sortedIntervals.end(), myfunction);
        
        vector<vector<int>> result;
        if (sortedIntervals.empty()) return result;
        
        result.push_back(sortedIntervals[0]);
        
        for (int i = 0; i < sortedIntervals.size(); i++) {
            if (sortedIntervals[i][0] <= result.back()[1]) {
                if (sortedIntervals[i][1] > result.back()[1])
                    result.back()[1] = sortedIntervals[i][1];
            } else {
                result.push_back(sortedIntervals[i]);
            }
        }
        return result;
    }
};