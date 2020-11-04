class Solution {
public:
    bool recurse(vector<int>& nums, int curIdx) {
        if (nums.empty()) return false;
        if (curIdx == nums.size() - 1) return true;
        if (nums[curIdx] == 0) return false;
        
        int cur = nums[curIdx];
        for (int i = 1; i <= cur; i++) {
            if (curIdx + i < nums.size()) {
                if (recurse(nums, curIdx + i)) return true;
            }
        }
        
        return false;
    }
    
    bool dp(vector<int>& nums) {
        vector<bool> table(nums.size(), false);
        
        table.back() = true;
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= nums.size() - 1) {
                table[i] = true;
            }
            else if (nums[i] == 0) {
                table[i] = false;
            }
            else {
                //look ahead nums[i] places from i
                for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                    if (table[i + j]) {
                        table[i] = true;
                        break;
                    }
                }
            }
        }
        
        return table[0];
    }
    
    bool greedy(vector<int>& nums) {
        int lastGoodPos = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastGoodPos) {
                lastGoodPos = i;
            }
        }
        
        return lastGoodPos == 0;
    }
    
    bool canJump(vector<int>& nums) {
        return greedy(nums);
        // return dp(nums); //This had one test failing on time limit
        // return recurse(nums, 0); //This had 2 tests failing on time limit
    }
};