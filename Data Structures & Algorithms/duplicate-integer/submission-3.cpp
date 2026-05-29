class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j != i && nums[j] == nums[i]) {
                    return true;
                }
            }
        }
        return false;
    }
};