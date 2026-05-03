#include<cstring>

class Solution {
public:
    int n;

    int memo[101][5001];

    int solve(int i, vector<int>& coins, int amount) {
        if(amount == 0) 
            return 1;
        
        if(i == n)
            return 0;
        
        if(memo[i][amount] != -1) return memo[i][amount];
        if(coins[i] > amount) {
            return memo[i][amount] = solve(i+1, coins, amount);
        }

        int take = solve(i, coins, amount - coins[i]);
        int skip = solve(i+1, coins, amount);

        return memo[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(memo, -1, sizeof(memo));
        return solve(0, coins, amount);
    }
};
