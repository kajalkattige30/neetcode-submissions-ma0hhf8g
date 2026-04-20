class Solution {
public:
    void traversal(vector<vector<int>>& grid, int i, int j, int row, 
                    int col, int& perimeter) {
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) {
            perimeter++;
            return;
        }

        if(grid[i][j] == -1) {
            return;
        }

        grid[i][j] = -1;
        traversal(grid, i-1, j, row, col, perimeter);
        traversal(grid, i+1, j, row, col, perimeter);
        traversal(grid, i, j-1, row, col, perimeter);
        traversal(grid, i, j+1, row, col, perimeter);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    traversal(grid, i, j, row, col, perimeter);
                }
            }
        }
        return perimeter;
    }
};