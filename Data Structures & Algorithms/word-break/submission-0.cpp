#include<cstring>

class Solution {
public:
    int n;

    unordered_set<string> st;

    int memo[301];

    bool solve(int idx, string& s) {
        if(idx >= n) return true;

        if(st.find(s.substr(idx, n - idx)) != st.end()) return true;

        if(memo[idx] != -1) return memo[idx];

        for(int l = 1; l <= s.length(); l++) {
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(idx + l, s)) {
                return memo[idx] = true;
            }
        }
        return memo[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        memset(memo, -1, sizeof(memo));

        for(string &word : wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};
