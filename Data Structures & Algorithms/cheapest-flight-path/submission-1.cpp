class Solution {
public:
    typedef pair<int, int> P;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int level = 0;
        queue<P> que;
        vector<int> price(n, INT_MAX);
        vector<vector<P>> adj(n);

        for(auto flight: flights) {
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];

            adj[u].push_back({v, cost});
        }

        que.push({src, 0});
        price[src] = 0;

        while(!que.empty() && level <= k) {
            int size = que.size();

            for(int i = 0; i < size; i++) {
                auto curr = que.front();
                que.pop();

                int u = curr.first;
                int cost = curr.second;

                for(auto &vec : adj[u]) {
                    int v = vec.first;
                    int addCost = vec.second;

                    if(cost + addCost < price[v]) {
                        que.push({v, cost + addCost});
                        price[v] = cost + addCost;
                    }
                }
            }
            level++;
        }

        return (price[dst] == INT_MAX) ? -1 : price[dst];
    }
};
