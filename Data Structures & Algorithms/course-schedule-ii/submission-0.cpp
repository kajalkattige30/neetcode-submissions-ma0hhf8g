class Solution {
public:

    vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        int count = 0;
        queue<int> que;

        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                count++;
                result.push_back(i);
            }
        }

        while(!que.empty()) {
            int u = que.front();
            que.pop();
            for(int &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                    count++;
                    result.push_back(v);
                }
            }
        }

        if(count == n) {
            return result;
        }
        return {};
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;

        for(vector<int> &vec: prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalSort(adj, numCourses, indegree);
    }
};
