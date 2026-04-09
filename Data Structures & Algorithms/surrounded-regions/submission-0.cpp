class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>>& visited) {
        if(i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }
        if(board[i][j] == 'X' || visited[i][j] == 1) {
            return;
        }

        visited[i][j] = 1;

        dfs(board, i-1, j, visited);
        dfs(board, i+1, j, visited);
        dfs(board, i, j-1, visited);
        dfs(board, i, j+1, visited);
    }


    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O' && visited[0][j] == 0) {
                dfs(board, 0, j, visited);
            }
            if(board[m-1][j] == 'O' && visited[m-1][j] == 0) {
                dfs(board, m-1, j, visited);
            }
        }

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && visited[i][0] == 0) {
                dfs(board, i, 0, visited);
            }
            if(board[i][n-1] == 'O' && visited[i][n-1] == 0) {
                dfs(board, i, n-1, visited);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && visited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
