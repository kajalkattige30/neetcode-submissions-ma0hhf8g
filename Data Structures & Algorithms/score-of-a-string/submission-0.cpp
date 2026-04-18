class Solution {
public:
    int scoreOfString(string s) {
        int n = s.length();
        int score = 0;
        for(int i = 1; i < n; i++) {
            int diff = abs((s[i-1] + 'a') - (s[i] + 'a'));
            score += diff;
        }
        return score;
    }
};