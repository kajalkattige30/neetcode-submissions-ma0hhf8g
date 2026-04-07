class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1,0}, {-1, 0}, {0,1}, {0, -1}};

    void DFS(vector<vector<int>>& matrix, int i, int j, int prevCellVal, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }
        if(visited[i][j] || matrix[i][j] < prevCellVal) {
            return;
        }

        visited[i][j] = true;
        for(auto dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(matrix, i_, j_, matrix[i][j], visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> result;
        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false));

        //Top row - already connected to the Pacific
        //Bottom row - already connected to the atlantic
        for(int j = 0; j < n; j++) {
            DFS(heights, 0, j, INT_MIN, pacificVisited);
            DFS(heights, m-1, j, INT_MIN, atlanticVisited);
        }

        //First column - already connected to the pacific
        //last column - already connected to the atlantic
        for(int i = 0; i < m; i++) {
            DFS(heights, i, 0, INT_MIN, pacificVisited);
            DFS(heights, i, n-1, INT_MIN, atlanticVisited);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    } 

    /*
    int m, n;
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,-1}, {0, 1}};

    bool DFSPacific(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
        if(i == 0 || j == 0) {
            return true;
        }

        visited[i][j] = true;

        for(auto dir: directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(new_i >= 0 && new_j >=0 && new_i < m && new_j < n && heights[new_i][new_j] <= heights[i][j] && !visited[new_i][new_j]) {
                if(DFSPacific(heights, new_i, new_j, visited) == true)
                    return true;
            }
        }


        return false;
    }

    bool DFSAtlantic(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
        if(i == m-1 || j == n-1) {
            return true;
        }

        visited[i][j] = true;

        for(auto dir: directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && !visited[new_i][new_j] && heights[new_i][new_j] <= heights[i][j]) {
                if(DFSAtlantic(heights, new_i, new_j, visited) == true)
                    return true;
            }
        }
        return false;
    }
     
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        m = heights.size();
        n = heights[0].size();
        

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vector<vector<bool>> visitedPacific(m, vector<bool>(n, false));
                vector<vector<bool>> visitedAtlantic(m, vector<bool>(n, false));
                if(DFSPacific(heights, i, j, visitedPacific) == true && DFSAtlantic(heights, i, j, visitedAtlantic) == true) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    } */
};
