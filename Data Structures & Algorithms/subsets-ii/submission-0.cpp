class Solution {
public:
    set<vector<int>> result;

    void solve(int idx, vector<int> &temp, vector<int>& nums) {
        if(idx >= nums.size()) {
            result.insert(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(idx+1, temp, nums);
        temp.pop_back();
        solve(idx+1, temp, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(0, temp, nums);
        for(vector<int> ele: result) {
            ans.push_back(ele);
        }
        return ans;
    }
};
