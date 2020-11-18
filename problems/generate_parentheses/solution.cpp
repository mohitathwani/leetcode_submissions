class Solution {
public:
    vector<string> result;
    string cur;
    
    void gen(int n, 
                       int open, 
                       int close
                      ) {
        
        if (cur.size() == 2 * n) {
            result.push_back(cur);
        }
        
        if (open < n) {
            cur.push_back('(');
            gen(n, open + 1, close);
            cur.pop_back();
        }
        
        if (close < open) {
            cur.push_back(')');
            gen(n, open , close + 1);
            cur.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        gen(n, 0, 0);
        return result;
    }
};