class Solution {
public:
    bool isMatch(string& s, string& p, int sI, int pI){
       if (sI == s.length() &&
           pI == p.length()) return true;
        
        //Case 1
        if (pI < p.length() - 1 && p[pI + 1] == '*') {
            // Match s as is with the rest of p
            if (isMatch(s, p, sI, pI + 2)) return true;
            
            // If s[sI] matches p[pI] but the next char is a *, match sI+1 with p
            if (sI < s.length() && (s[sI] == p[pI] || p[pI] == '.'))
            return isMatch(s, p, sI + 1, pI);
        }
        
        //Case 2
        else if (sI < s.length() && pI < p.length()) {
            if (s[sI] == p[pI] || p[pI] == '.') {
                return isMatch(s, p, sI + 1, pI + 1);
            }
        } else {
            return false;
        }
        
        return false;
    }
    
    bool isMatch(string s, string p) {
        return isMatch(s, p, 0, 0);
    }
};