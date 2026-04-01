class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int s = 0;
        int e = nums.size()-1;
        while(s <= e) {
            int mid = s + (e-s)/2;
            if(nums[mid] == target) {
                ans = mid;
                break;
            }
            if(nums[s] <= nums[mid]) {
                if(nums[s] <= target && target < nums[mid]) {
                    e = mid-1;
                }
                else {
                    s = mid+1;
                }
            }
            else {
                if(nums[mid] < target && target <= nums[e]) {
                    s = mid+1;
                }
                else {
                    e = mid-1;
                }
            }
        }
        return ans;
    }
};
