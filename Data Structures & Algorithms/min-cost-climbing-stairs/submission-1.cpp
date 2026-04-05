#include<cstring>
class Solution {
public:
    int n;
    int dp[101];
    int solve(int i, vector<int>& nums) {
        if(i >= n) 
            return 0;

        if(dp[i] != -1) 
            return dp[i];
        
        int a = nums[i] + solve(i+1, nums);
        int b = nums[i] + solve(i+2, nums);
        return dp[i] = min(a, b);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        memset(dp, -1, sizeof(dp));
        return min(solve(0, cost), solve(1, cost));
    }
};
