class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i < s.length()) {
            int delimiterPos = s.find("#", i);
            int len = stoi(s.substr(i, delimiterPos - i));
            i = delimiterPos + 1;
            result.push_back(s.substr(i, len));
            i += len;
        }
        return result;
    }
};
