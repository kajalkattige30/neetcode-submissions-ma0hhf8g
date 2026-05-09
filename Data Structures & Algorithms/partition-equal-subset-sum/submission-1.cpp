#include<cstring>

class Solution {
public:
    int t[101][5001];

    bool solve(vector<int>& nums, int i, int x) {
        if(x == 0) return true;

        if(i >= nums.size()) return false;

        if(t[i][x] != -1) return t[i][x];

        bool take = false;
        if(x >= nums[i]) {
            take = solve(nums, i+1, x - nums[i]);
        }

        bool not_take = solve(nums, i+1, x);

        return t[i][x] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if(sum % 2 != 0) return false;
        memset(t, -1, sizeof(t));

        return solve(nums, 0, sum/2);
    }
};
