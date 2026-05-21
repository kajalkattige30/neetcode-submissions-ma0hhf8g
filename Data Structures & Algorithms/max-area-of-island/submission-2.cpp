class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j, int m,
                    int n, int &area) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }

        if(grid[i][j] == -1) {
            return;
        }

        area += 1;
        grid[i][j] = -1;
        dfs(grid, i, j-1, m, n, area);
        dfs(grid, i, j+1, m, n, area);
        dfs(grid, i-1, j, m, n, area);
        dfs(grid, i+1, j, m, n, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mxArea = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int area = 0;
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, m, n, area);
                    mxArea = max(mxArea, area);
                }
            }
        }
        return mxArea;
    }
};
