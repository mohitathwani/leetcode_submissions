class Solution {
public:
    bool isPossible(vector<int>& nums, int numSubArrays, int maxSum) {
        int numSplits = 0;
        int curSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            
            if (nums[i] > maxSum) return false;
            
            if (curSum > maxSum) {
                numSplits++;
                curSum = nums[i];
            }
        }
        
        numSplits++;
        if (numSplits <= numSubArrays) return true;
        return false;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int lo = 0;
        int hi = 0;
        
        int result = 0;
        for (const auto& n : nums) {
            hi += n;
        }
        
        while (lo <= hi) {
            int mid = lo + ((hi - lo) / 2);
            
            if (isPossible(nums, m, mid)) {
                result = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        } 
        
        return result;
    }
};