class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1freq[26] = {0};
        int s2freq[26] = {0};
        int matches = 0;
        int l = 0;
        int r = s1.length();

        for(int i = 0; i < s1.length(); i++) {
            s1freq[s1[i] - 'a']++;
            s2freq[s2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(s1freq[i] == s2freq[i]) matches++;
        }

        while(r < s2.length()) {
            if(matches == 26) return true;

            int index = s2[r] - 'a';
            s2freq[index]++;
            if(s1freq[index] == s2freq[index]) {
                matches++;
            }
            else if(s1freq[index] + 1 == s2freq[index]) {
                matches--;
            }

            index = s2[l] - 'a';
            s2freq[index]--;
            if(s1freq[index] == s2freq[index]) {
                matches++;
            }
            else if(s1freq[index] - 1 == s2freq[index]) {
                matches--;
            }
            l++;
            r++;
        }
        return (matches == 26);
    }
};
