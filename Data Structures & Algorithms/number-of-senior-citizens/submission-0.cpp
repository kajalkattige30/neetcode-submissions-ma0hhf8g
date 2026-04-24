class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string &str : details) {
            string age = str.substr(11, 2);
            int ageInt = stoi(age);
            if(ageInt > 60) count++;
        }
        return count;
    }
};