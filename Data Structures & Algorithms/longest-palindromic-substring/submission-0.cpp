class Solution {
public:
    bool checkPalindrome(string &s, int i, int j) {
        if(i >= j) {
            return true;
        }

        if(s[i] == s[j]) {
            return checkPalindrome(s, i+1, j-1);
        }
        else {
            return false;
        }
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        int sp = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(checkPalindrome(s, i, j) == true) {
                    if((j - i + 1) > maxLen) {
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};
