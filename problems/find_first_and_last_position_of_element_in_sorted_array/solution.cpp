/**
0 1 2 3 4 5 6
1 2 3 3 3 4 5
*/
class Solution {
public:
    int search(vector<int>& nums, int target, bool searchLeft) {
        int lo = 0;
        int hi = nums.size() - 1;
        int pos = -1;
        
        while (lo <= hi) {
            int mid = lo + ((hi - lo) / 2);
            
            if (nums[mid] == target) {
                pos = mid;
                if (searchLeft) {
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
            else if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        
        return pos;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = search(nums, target, true);
        int right = search(nums, target, false);
        
        vector<int> result = {left, right};
        return result;
    }
};