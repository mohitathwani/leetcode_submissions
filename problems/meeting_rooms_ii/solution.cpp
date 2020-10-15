bool comparator (vector<int> i, vector<int> j) { return (i[0]<j[0]); }
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        /*
        vector<vector<int>> sorted = intervals;
        sort(sorted.begin(), sorted.end(), comparator);
        
        
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(sorted[0][1]);
        
        for (int i = 1; i < sorted.size(); i++) {
            int prevStart = sorted[i - 1][0];
            int prevEnd = pq.top();
            int curStart = sorted[i][0];
            int curEnd = sorted[i][1];
            
            if (curStart >= prevEnd) {
                pq.pop();
            }
            
            pq.push(curEnd);
        }
        
        return pq.size();
        */
        
        vector<int> startTimes;
        for (int i = 0; i < intervals.size(); i++) {
            startTimes.push_back(intervals[i][0]);
        }
        sort(startTimes.begin(), startTimes.end());
        
        vector<int> endTimes;
        for (int i = 0; i < intervals.size(); i++) {
            endTimes.push_back(intervals[i][1]);
        }
        sort(endTimes.begin(), endTimes.end());
        
        int numRooms = 0;
        int curEndIdx = 0;
        
        for (int i = 0; i < startTimes.size(); i++) {
            if (startTimes[i] < endTimes[curEndIdx]) {
                numRooms++;
            } else {
                curEndIdx++;
            }
        }
        return numRooms;
    }
};