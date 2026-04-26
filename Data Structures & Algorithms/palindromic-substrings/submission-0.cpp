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
    
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(checkPalindrome(s, i, j) == true) {
                    count++;
                }
            }
        }
        return count;
    }
};
