class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto &num : nums) {
            freq[num]++;
        }

        for(auto &it : freq) {
            if(it.second >= 2) return true;
        }
        return false;
    }
};