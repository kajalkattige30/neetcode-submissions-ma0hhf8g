class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for(int i = 1; i < n; i++) {
            left[i] = left[i-1]*nums[i-1];
        }

        for(int i = n-2; i >= 0; i--) {
            right[i] = right[i+1]*nums[i+1];
        }

        vector<int> result;
        for(int i = 0; i < n; i++) {
            result.push_back(left[i] * right[i]);
        }
        return result;
    }
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> result;

    //     for(int i = 0; i < nums.size(); i++) {
    //         int pro = 1;
    //         for(int j = 0; j < nums.size(); j++) {
    //             if(i == j) continue;
    //             pro = pro * nums[j];
    //         }
    //         result.push_back(pro);
    //     }
    //     return result;
    // }
};
