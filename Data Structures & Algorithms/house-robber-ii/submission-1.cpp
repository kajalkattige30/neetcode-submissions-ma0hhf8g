#include<cstring>
class Solution {
public:
    // Bottom up
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> t(n+1, 0);
        t[0] = 0;

        //case 1: steal from 1st house

        for(int i = 1; i <= n-1; i++) {
            int skip = t[i-1];
            int steal = nums[i-1] + (i-2 >= 0 ? t[i-2] : 0);
            t[i] = max(skip, steal);
        }
        int result1 = t[n-1];

        t.clear();
        t[0] = 0;
        t[1] = 0;

        //case 2: skip 1st house
        for(int i = 2; i <= n; i++) {
            int skip = t[i-1];
            int steal = nums[i-1] + t[i-2];
            t[i] = max(skip, steal);
        }
        int result2 = t[n];

        return max(result1, result2);
    }
    /* Top Down: Memoization
    int t[101];

    int solve(vector<int>& nums, int start, int end) {
        if(start > end) {
            return 0;
        }
        if(t[start] != -1) {
            return t[start];
        }

        int steal = nums[start] + solve(nums, start + 2, end);
        int skip  = solve(nums, start + 1, end);

        return t[start] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        memset(t, -1, sizeof(t));
        int case1 = solve(nums, 0, n-2);
        memset(t, -1, sizeof(t));
        int case2 = solve(nums, 1, n-1);

        return max(case1, case2);
    }
    */
};
