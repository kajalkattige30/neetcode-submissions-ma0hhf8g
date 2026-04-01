class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mx = 0;
        int l = 0;
        int r = heights.size() - 1;
        while(l < r) {
            int cap = min(heights[l], heights[r]) * (r - l);
            mx = max(mx, cap);
            if(heights[r] < heights[l]) r--;
            else l++;
        }
        return mx;
    }
};
