class Solution {
public:
    bool isAnagram(string s, string t) {
        int sfreq[26] = {0};
        int tfreq[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            sfreq[s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++) {
            tfreq[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(sfreq[i] != tfreq[i]) return false;
        }
        return true;
    }
};
