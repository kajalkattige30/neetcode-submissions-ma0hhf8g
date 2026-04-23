class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int len = 0;
        
        int ptr = n-1;

        while(ptr >= 0 && s[ptr] == ' ') {
            ptr--;
        }

        while(ptr >= 0 && s[ptr] != ' ') {
            len++;
            ptr--;
        }
        return len;
    }
};