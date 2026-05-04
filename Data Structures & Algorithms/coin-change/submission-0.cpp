#include<cstring>

class Solution {
public:
    int memo[11][10001];

    int solve(int i, vector<int>& coins, int amount) {
        if(i == 0) {
            if((amount % coins[0]) == 0) {
                return memo[i][amount] = amount/coins[0];
            }
            return memo[i][amount] = 1e9;
        }

        if(memo[i][amount] != -1) return memo[i][amount];

        int take = INT_MAX;
        if(coins[i] <= amount) {
            take = 1 + solve(i, coins, amount - coins[i]);
        }
        int not_take = solve(i-1, coins, amount);

        return memo[i][amount] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(memo, -1, sizeof(memo));
        int ans = solve(n-1, coins, amount);
        if(ans >= 1e9) return -1;
        return ans;
    }
};
