class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        int n = nums.size();

        for(int i = 0; i<n; i++) {
            mp[nums[i]]++;
        }

        for(auto &it: mp) {
            min_heap.push({it.second, it.first});
            if(min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> result;
        while(!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return result;
    }
};
