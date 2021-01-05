class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum = 0;
        int windowSum = 0;
        int N = cardPoints.size();
        int windowSize = N - k;
        
        for (size_t i = 0; i < N; i++) {
            totalSum += cardPoints[i];
            if (i < windowSize) {
                windowSum = totalSum;
            }
        }
        
        int maxSum = totalSum - windowSum;
        int left = 0;
        int right = windowSize;
        for (int i = right; i < N; i++) {
            windowSum += cardPoints[right++] - cardPoints[left++];
            maxSum = max(maxSum, totalSum - windowSum);
        }
        return maxSum;
    }
};