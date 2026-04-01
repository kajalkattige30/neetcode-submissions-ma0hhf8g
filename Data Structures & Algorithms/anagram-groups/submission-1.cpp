class Solution {
public:
    string generate(string word) {
        string result = "";
        int freq[26] = {0};

        for(char &ch: word) {
            freq[ch-'a']++;
        }

        for(int i = 0; i<26; i++) {
            int f = freq[i];
            if(f > 0) {
                result += string(f, i+'a');
            }
        }
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        int n = strs.size();
        
        for(int i = 0; i<n; i++) {
            string word = strs[i];

            string new_word = generate(word);

            mp[new_word].push_back(word);
        }

        for(auto &it: mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};
