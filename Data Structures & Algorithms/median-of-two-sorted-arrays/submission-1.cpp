class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int total_length = m + n;

        int low = 0;
        int high = m;

        while(low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = (total_length + 1)/2 - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            int r1 = cut1 == m ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n ? INT_MAX : nums2[cut2];

            if(l1 <= r2 && l2 <= r1) {
                if(total_length%2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else {
                    return max(l1, l2);
                }
            }
            else if(l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};
