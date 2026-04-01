class Solution {
public:
    
    int count2(int num) {
        int cnt = 0;
        while(num > 0) {
            int rem = num % 2;
            cnt += rem;
            num = num / 2;
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0; i <= n; i++) {
            ans.push_back(count2(i));
        }

        return ans;
        
    }
};
