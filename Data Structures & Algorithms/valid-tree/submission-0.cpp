class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        
        for (int neighbor : adj[node]) {
            // If the neighbor is already visited and it's not the parent, we have a cycle
            if (visited[neighbor] && neighbor != parent) {
                return false;
            }
            
            // If not visited, we continue DFS traversal
            if (!visited[neighbor] && !dfs(neighbor, node, adj, visited)) {
                return false;
            }
        }
        
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;  // A valid tree must have exactly n - 1 edges
        }
        
        vector<vector<int>> adj(n);  // Adjacency list to represent the graph
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        
        // Start DFS from node 0
        if (!dfs(0, -1, adj, visited)) {
            return false;  // If a cycle is detected or not all nodes are visited
        }
        
        // If all nodes are visited, then it's a valid tree
        for (bool nodeVisited : visited) {
            if (!nodeVisited) {
                return false;  // There are disconnected components
            }
        }
        
        return true;
    }
};
