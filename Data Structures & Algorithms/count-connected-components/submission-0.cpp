class Solution {
public:

    void dfs(int node, vector<bool>& visited, const vector<vector<int>>& adj) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj); // Recur for unvisited neighbors
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Track visited nodes
        vector<bool> visited(n, false);

        // Step 3: Count connected components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, visited, adj); // Start DFS from this unvisited node
            }
        }

        return components;
    }
};
