class Solution {
public:

    void solve(int start, int sum, int target, vector<int>& nums, vector<int> &temp, vector<vector<int>>& result) {
        if(sum == target) {
            result.push_back(temp);
            return;
        }

        if(sum > target || start == nums.size()) {
            return;
        }

        temp.push_back(nums[start]);
        solve(start, sum + nums[start], target, nums, temp, result);

        temp.pop_back();
        solve(start+1, sum, target, nums, temp, result);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int sum = 0;
        
        solve(0, sum, target, nums, temp, result);

        return result;
    }
};
