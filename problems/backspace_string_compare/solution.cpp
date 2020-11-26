class Solution {
public:
    string build(string A) {
        string a;
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == '#') {
                if (!a.empty())
                    a.pop_back();
            }
            else {
                a.push_back(A[i]);
            }
        }
        return a;
    }
    bool backspaceCompare(string S, string T) {
        return build(S) == build(T);
    }
};