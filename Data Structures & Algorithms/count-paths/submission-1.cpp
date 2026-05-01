#include<cstring>

class Solution {
public:
    int memo[101][101];

    int solve(int i, int j, int m, int n) {
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        if(i == m-1 && j == n-1) { //reached destination
            return memo[i][j] = 1;
        }

        if(i >= m || j >= n) {
            return memo[i][j] = 0;
        }

        return memo[i][j] = solve(i+1, j, m, n) + solve(i, j+1, m, n);
    }

    int uniquePaths(int m, int n) {
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, m, n);
    }
};
