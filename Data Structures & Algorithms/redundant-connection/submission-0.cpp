class Solution {
public:
    // Find function with path compression
    int find(int node, vector<int>& parent) {
        if (parent[node] != node) {
            parent[node] = find(parent[node], parent); // Path compression
        }
        return parent[node];
    }

    // Union function with union by rank
    void unionNodes(int node1, int node2, vector<int>& parent, vector<int>& rank) {
        int root1 = find(node1, parent);
        int root2 = find(node2, parent);

        if (root1 != root2) {
            // Union by rank
            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root2] = root1;
                rank[root1]++; // Increase rank if both roots are of same rank
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        // Initialize the parent of each node to itself
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        // Process each edge
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            // If u and v are already connected, this edge is redundant
            if (find(u, parent) == find(v, parent)) {
                return edge;
            } else {
                unionNodes(u, v, parent, rank);
            }
        }

        return {}; // This won't be reached since there is always a redundant edge
    }
};
