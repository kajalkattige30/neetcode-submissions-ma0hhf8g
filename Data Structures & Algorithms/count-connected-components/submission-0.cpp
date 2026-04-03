class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find_parent(int x) {
        if(x == parent[x]) {
            return x;
        }

        return parent[x] = find_parent(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find_parent(x);
        int y_parent = find_parent(y);

        if(x_parent == y_parent) {
            return;
        }

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if(rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int components = n;
        parent.resize(n);
        rank.resize(n, -1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(vector<int> &e: edges) {
            int a = e[0];
            int b = e[1];

            int parent_a = find_parent(a);
            int parent_b = find_parent(b);

            if(parent_a != parent_b) {
                Union(a, b);
                components -= 1;
            }
        }
        return components;
    }
};
