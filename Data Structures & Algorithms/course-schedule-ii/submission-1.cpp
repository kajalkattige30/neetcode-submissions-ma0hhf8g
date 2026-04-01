class Solution {
public:

    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, stack<int> &st, vector<bool> &inRecursion, bool &hasCycle) {
        visited[u] = true;
        inRecursion[u] = true;

        for(int &v : adj[u]) {
            if(!visited[v]) {
                DFS(adj, v, visited, st, inRecursion, hasCycle);
            }
            if(inRecursion[v]) {
                hasCycle = true;
                return;
            }
        }

        inRecursion[u] = false;
        st.push(u);
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        bool hasCycle = false;

        for(auto &it: prerequisites) {
            int a = it[0];
            int b = it[1];

            //b--->a
            adj[b].push_back(a);
        }

        stack<int> st;
        vector<int> result;

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                DFS(adj, i, visited, st, inRecursion, hasCycle);
            }
        }

        if(hasCycle == true) {
            return {};
        }

        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }

    // vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
    //     int count = 0;
    //     queue<int> que;

    //     vector<int> result;

    //     for(int i = 0; i < n; i++) {
    //         if(indegree[i] == 0) {
    //             que.push(i);
    //             count++;
    //             result.push_back(i);
    //         }
    //     }

    //     while(!que.empty()) {
    //         int u = que.front();
    //         que.pop();
    //         for(int &v : adj[u]) {
    //             indegree[v]--;
    //             if(indegree[v] == 0) {
    //                 que.push(v);
    //                 count++;
    //                 result.push_back(v);
    //             }
    //         }
    //     }

    //     if(count == n) {
    //         return result;
    //     }
    //     return {};
    // }


    // vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<int> indegree(numCourses, 0);
    //     unordered_map<int, vector<int>> adj;

    //     for(vector<int> &vec: prerequisites) {
    //         int a = vec[0];
    //         int b = vec[1];

    //         adj[b].push_back(a);
    //         indegree[a]++;
    //     }

    //     return topologicalSort(adj, numCourses, indegree);
    // }
};
