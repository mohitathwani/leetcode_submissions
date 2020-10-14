class Solution {
public:
    void initializeMatrix(vector<vector<bool> >& matrix, int N) {
        for (int i = 0; i < N; i++) {
            vector<bool> row;
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    row.push_back(true);
                } else {
                    row.push_back(false);
                }
            }
            matrix.push_back(row);
        }
    }
    
    string longestPalindrome2(string s) {
        int N = s.size();
        
        if (N == 1 || N == 0) return s;
        
        vector<vector<bool> >matrix;
        initializeMatrix(matrix, N);
        
        int maxLen = 1;
        int start = 0;
        
        int startCol = 1;
        for (int i = 1; i < N; i++) {
            int row = 0;
            for (int col = startCol; col < N; col++) {
                if (s[row] == s[col]) {
                    if (col - row == 1) {
                        matrix[row][col] = true;
                    } else {
                        matrix[row][col] = matrix[row + 1][col - 1];
                    }
                    
                    if (matrix[row][col] == true) {
                        if (maxLen < (col - row + 1)) {
                        maxLen = col - row + 1;
                        start = row;
                    }
                    }
                    
                }
                row++;
            }
            startCol++;
        }
        return s.substr(start, maxLen);
    }
    
    
    string expandAround(string s, int p1, int p2) {
        string result;
        
        while(p1 >= 0 && p2 < s.size() && s[p1] == s[p2]) {
            p1--;
            p2++;
        }
        
        result = s.substr(p1 + 1, p2 - p1 - 1);
        return result;
    }
    
    string longestPalindrome(string s) {
        int N = s.size();
        if (N < 1) return s;
        
        int maxLen = 0;
        string result;
        
        for (int i = 0; i < N; i++) {
            string s1 = expandAround(s, i, i);
            if (s1.size() > maxLen) {
                maxLen = s1.size();
                result = s1;
            }
            
            s1 = expandAround(s, i, i+1);
            if (s1.size() > maxLen) {
                maxLen = s1.size();
                result = s1;
            }
        }
        return result;
    }
};;