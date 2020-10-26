class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>();
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> triplets;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int bPc = 0 - a;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int numsLeft = nums[left];
                int numsRight = nums[right];
                
                if (numsLeft + numsRight == bPc) {
                    vector<int> triplet = {a, numsLeft, numsRight};
                    triplets.insert(triplet);
                    left++;
                    right--;
                }
                else if (numsLeft + numsRight < bPc) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return vector<vector<int>>(triplets.begin(), triplets.end());
    }
};