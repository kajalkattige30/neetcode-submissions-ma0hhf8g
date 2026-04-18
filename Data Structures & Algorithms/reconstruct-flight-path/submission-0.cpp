class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> result;
    int numTickets = 0;

    bool DFS(string fromAirport, vector<string>& path) {
        path.push_back(fromAirport);

        if(path.size() == numTickets + 1) {
            result = path;
            return true;
        }

        vector<string>& neighbors = adj[fromAirport];

        for(int i = 0; i < neighbors.size(); i++) {
            string toAirport = neighbors[i];

            neighbors.erase(neighbors.begin() + i);

            if(DFS(toAirport, path) == true) 
                return true;
            
            neighbors.insert(neighbors.begin() + i, toAirport);
        }

        path.pop_back();
        return false;
        
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numTickets = tickets.size();
        vector<string> path;

        for(auto t : tickets) {
            string u = t[0];
            string v = t[1];
            adj[u].push_back(v);
        }

        for(auto &edges : adj) {
            sort(edges.second.begin(), edges.second.end());
        }

        DFS("JFK", path);

        return result;
    }
};
