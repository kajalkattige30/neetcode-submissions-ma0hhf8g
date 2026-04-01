class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; i--) {
            if(digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                return digits;
            }
        }
        vector<int> ans(digits.size()+1, 0);
        ans[0] = 1;
        return ans;
    }
};
