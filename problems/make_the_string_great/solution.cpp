#include <cmath> 

class Solution {
public:
    string makeGood(string s) {
        int prevLen = 0;
        while(s.length() != prevLen && s.length() >= 2) {
            prevLen = s.length();
            //Find pair to remove
            for(int i = 0; i <= s.length() - 2; i++) {
                if(abs(s[i] - s[i + 1]) == 32) {
                    s.erase(i, 2);
                    break;
                }
            }
        }
        return s;
    }
};