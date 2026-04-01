class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int sum = 0;
        int maxsum = INT_MIN;
        while(i < nums.size()) {
            sum += nums[i];
            maxsum = max(maxsum, sum);
            if(sum < 0) sum = 0;
            i++;
        }
        return maxsum;
    }
};
