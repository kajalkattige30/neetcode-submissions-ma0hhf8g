class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        set<int> good;

        for(int i = 0; i < n; i++) {
            vector<int> curr = triplets[i];
            if(curr[0] > target[0] || curr[1] > target[1] || curr[2] > target[2]) {
                continue;
            }

            for(int j = 0; j < 3; j++) {
                if(curr[j] == target[j]) {
                    good.insert(j);
                }
            }
        }
        return (good.size() == 3);
    }
};
