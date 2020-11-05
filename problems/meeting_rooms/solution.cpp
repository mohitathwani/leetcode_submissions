bool comparator (vector<int>i, vector<int>j) {return i[0] < j[0];}
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<vector<int>> sorted = intervals;
        sort(sorted.begin(), sorted.end(), comparator);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (sorted[i][0] < sorted[i - 1][1]) return false;
        }
        return true;
    }
};