class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for(auto &vec: times) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            mp[u].push_back({v, w});
        }

        vector<int> result(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        result[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            int d    = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &vec: mp[node]) {
                int adjNode = vec.first;
                int dist    = vec.second;

                if(d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }

        int mx = INT_MIN;
        for(int i = 1; i <= n; i++) {
            if(result[i] == INT_MAX) return -1;
            mx = max(mx, result[i]);
        }
        return mx;
    }
};
