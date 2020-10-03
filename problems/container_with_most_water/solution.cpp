#include <algorithm> 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = -1;
        
        int i = 0;
        int j = height.size() - 1;
        
        int delta;
        while(delta = j - i) {
            int length = std::min(height[i], height[j]);
            result = std::max(length * delta, result);
            
            if(height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        
        return result;
    }
};