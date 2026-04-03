class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if(i == parent[i]) {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

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
            parent[y_parent] = x_parent;
            rank[x_parent] += 1;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> result(2);
        int components = edges.size();

        parent.resize(components+1);
        rank.resize(components+1, -1);

        for(int i = 1; i <= components; i++) {
            parent[i] = i;
        }

        for(vector<int> &e: edges) {
            int a = e[0];
            int b = e[1];

            int a_parent = find(a);
            int b_parent = find(b);

            if(a_parent != b_parent) {
                Union(a, b);
                components -= 1;
            }
            else {
                result[0] = a;
                result[1] = b;
            }
        }
        return result;
    }
};
