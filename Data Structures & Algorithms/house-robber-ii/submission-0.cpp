#include<cstring>
class Solution {
public:
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
};
