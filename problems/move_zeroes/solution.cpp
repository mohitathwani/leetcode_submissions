class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertAt = 0;
        
        for (const auto& num : nums) {
            if (num != 0) {
                nums[insertAt++] = num;
            }
        }
        
        for (int i = insertAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};