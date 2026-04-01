class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == (char)48) {
            return;
        }

        if(grid[i][j] == (char)36) {
            return;
        }

        grid[i][j] = (char)36;
        dfs(grid, i, j-1, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i+1, j, m, n);
    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == (char)49) {
                    dfs(grid, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};
