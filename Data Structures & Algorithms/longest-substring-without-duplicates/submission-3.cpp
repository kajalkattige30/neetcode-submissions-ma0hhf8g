class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int maxLen = 0;
        vector<int> hash(256, -1);
        int l = 0;
        int r = 0;
        while(r < s.length()) {
            if(hash[s[r]] != -1) {
                if (l <= hash[s[r]]) {
                    l = hash[s[r]] + 1;
                }
            }
            len = r - l + 1;
            maxLen = max(maxLen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
