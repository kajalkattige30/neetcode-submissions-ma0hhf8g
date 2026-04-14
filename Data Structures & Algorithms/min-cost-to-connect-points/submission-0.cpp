class Solution {
public:
    typedef pair<int, int> P;

    int PrimsAlgo(vector<vector<P>>& adj, int V) {
        vector<bool> inMST(V, false);
        priority_queue<P, vector<P>, greater<P>> pq;
        int sum = 0;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto u = pq.top();
            pq.pop();

            int wt = u.first;
            int node = u.second;

            if(inMST[node] == true) {
                continue;
            }

            inMST[node] = true;
            sum += wt;

            for(auto &v : adj[node]) {
                int neighbor = v.first;
                int wt = v.second;

                if(inMST[neighbor] == false) {
                    pq.push({wt, neighbor});
                }
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<P>> adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        return PrimsAlgo(adj, n);
    }
};
