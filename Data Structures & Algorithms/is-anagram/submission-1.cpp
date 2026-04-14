class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_freq(26);
        vector<int> t_freq(26);

        for(char ch: s) {
            s_freq[ch - 'a']++;
        }

        for(char ch: t) {
            t_freq[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(s_freq[i] != t_freq[i]) return false;
        }
        return true;
    }
};
