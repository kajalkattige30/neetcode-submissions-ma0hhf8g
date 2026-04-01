class Solution {
public:
    int findMin(vector<int> &nums) {
        int s = 0;
        int e = nums.size()-1;

        if(nums.size() == 1) return nums[s];

        if(nums[s] < nums[e]) return nums[s];

        while(s < e) {
            int mid = s + (e-s)/2;

            if(nums[mid] > nums[e]) {
                s = mid+1;
            }
            else {
                e = mid;
            }
        }
        return nums[s];
    }
};
