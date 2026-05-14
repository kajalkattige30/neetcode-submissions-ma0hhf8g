class Solution {
public:
    int solve(vector<int>& nums, int idx, int currSum, int target) {
        if(idx == nums.size()) {
            if(currSum == target) {
                return 1;
            }
            else return 0;
        }

        int plus = solve(nums, idx+1, currSum + nums[idx], target);
        int minus = solve(nums, idx+1, currSum - nums[idx], target);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
};
