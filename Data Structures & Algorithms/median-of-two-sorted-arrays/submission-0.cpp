class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size();
        int n = nums2.size();
        vector<int> temp;

        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m) {
            temp.push_back(nums1[i]);
            i++;
        }
        while(j < n) {
            temp.push_back(nums2[j]);
            j++;
        }
        
        double ans = 0.0;
        int size = temp.size();
        if(size%2 == 1) {
            ans = temp[size/2];
        }
        else {
            ans = (temp[size/2] + temp[size/2-1])/2.0;
        }
        return ans;
    }
};
