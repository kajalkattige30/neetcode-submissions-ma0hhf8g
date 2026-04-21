class Solution {
public:
    void traversal(vector<vector<int>>& grid, int i, int j, int m, int n, int color, int startColor) {
        if(i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }

        if(grid[i][j] != startColor) {
            return;
        }

        grid[i][j] = color;
        traversal(grid, i-1, j, m, n, color, startColor);
        traversal(grid, i+1, j, m, n, color, startColor);
        traversal(grid, i, j-1, m, n, color, startColor);
        traversal(grid, i, j+1, m, n, color, startColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();


        int startColor = image[sr][sc];
        if(startColor == color) return image;

        traversal(image, sr, sc, row, col, color, startColor);

        return image;
    }
};