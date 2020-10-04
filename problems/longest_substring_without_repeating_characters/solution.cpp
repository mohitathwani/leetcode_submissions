#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seenSet;
        int result = 0;
        
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                char c = s[j];
                if (seenSet.count(c) == 0) {
                    seenSet.insert(c);
                    result = std::max(result, (int)seenSet.size());
                }
                else {
                    seenSet.clear();
                    break;
                }   
            }
        }
        
        return result;
    }
};