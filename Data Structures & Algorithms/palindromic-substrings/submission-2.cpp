#include<cstring>

class Solution {
public:

    int t[1001][1001];

    bool checkPalindrome(string &s, int i, int j) {
        if(i > j) {
            return 1;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(s[i] == s[j]) {
            return t[i][j] = checkPalindrome(s, i+1, j-1);
        }
        else {
            return 0;
        }
    }

    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        memset(t, -1, sizeof(t));

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
