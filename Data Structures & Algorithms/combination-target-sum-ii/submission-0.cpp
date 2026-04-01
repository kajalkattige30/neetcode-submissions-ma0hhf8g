class Solution {
public:

    void solve(vector<int> &candidates, int target, int idx, vector<int>& temp, vector<vector<int>> &result) {
        if(target < 0) return;

        if(target == 0) {
            result.push_back(temp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue;

            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i+1, temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, temp, result);
        return result;
    }
};
