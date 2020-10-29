class Solution {
public:
    void recurse(vector<vector<char>>& g, int x, int y) {
        vector<vector<int>> directions {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
                    
        for (int d = 0; d < directions.size(); d++) {
            int nX = x + directions[d][0];
            int nY = y + directions[d][1];
            if (nX >= 0 && nX < g.size() && nY >=0 && nY < g[0].size()) {
               if (g[nX][nY] == '1') {
                    g[nX][nY] = '0';
                    recurse(g, nX, nY);
                }
            } 
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> gCopy = grid;
        int count = 0;
        
        int r = gCopy.size();
        int c = gCopy[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (gCopy[i][j] == '1') {
                    count++;
                    recurse(gCopy, i, j);
                }
            }
        }
        
        return count;
    }
};