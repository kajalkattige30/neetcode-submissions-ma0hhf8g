#include<cstring>
class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(vector<int>& nums, int i, int p) {
        if(i >= nums.size()) {
            return 0;
        }
        if(p != -1 && dp[i][p] != -1) {
            return dp[i][p];
        }
        int take = 0;
        if(p == -1 || nums[p] < nums[i]) {
            take = 1 + solve(nums, i+1, i);
        }
        
        int skip = solve(nums, i+1, p);
        return dp[i][p] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};
