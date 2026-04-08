#include<cstring>
class Solution {
public:

    // Bottom up approach:
    int lengthOfLIS(vector<int>& nums) {
        int maxLIS = 1;
        int n = nums.size();
        vector<int> t(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    t[i] = max(t[i], 1 + t[j]);
                    maxLIS = max(maxLIS, t[i]);
                }
                
            }
        }
        return maxLIS;
    }

    /* top down approach
    int n;
    int dp[1001][1001];
    int solve(vector<int>& nums, int i, int p) {
        if(i >= n) {
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
    } */
};
