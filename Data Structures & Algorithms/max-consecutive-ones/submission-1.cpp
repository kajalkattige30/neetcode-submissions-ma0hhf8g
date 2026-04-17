class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0;
        int mx = INT_MIN;

        for(int n : nums) {
            if(n == 1) {
                len++;
                mx = max(mx, len);
            }
            else {
                len = 0;
            }
        }
        return (mx == INT_MIN) ? 0 : mx;
    }
};