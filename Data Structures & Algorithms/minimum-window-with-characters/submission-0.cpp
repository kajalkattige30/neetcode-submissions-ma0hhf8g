class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        int m = t.length();
        int n = s.length();
        int cnt = 0;
        int l = 0;
        int r = 0;
        int minLen = INT_MAX;
        int sIndex = -1;

        for(int i=0; i < m; i++) {
            hash[t[i]]++;
        }

        while(r < n) {
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            while(cnt == m) {
                int len = r - l + 1;
                if(len < minLen) {
                    minLen = len;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return sIndex == -1? "": s.substr(sIndex, minLen);
    }
};
