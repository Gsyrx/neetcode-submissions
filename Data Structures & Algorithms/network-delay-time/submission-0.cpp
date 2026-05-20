class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Create an adjacency list to represent the graph
        vector<vector<pair<int, int>>> graph(n + 1);  // graph[i] = {neighbor, weight}
        for (const auto& time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        // Step 2: Dijkstra's algorithm setup
        vector<int> dist(n + 1, INT_MAX);  // Distance from the source k
        dist[k] = 0;  // Distance to itself is 0
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});  // {distance, node}
        
        // Step 3: Dijkstra's algorithm to find the shortest time to all nodes
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (d > dist[node]) continue;  // Skip if this is an outdated entry
            
            // Explore all the neighbors of the current node
            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                
                // If a shorter path to nextNode is found, update its distance
                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        
        // Step 4: Find the maximum distance (the slowest time)
        int maxTime = *max_element(dist.begin() + 1, dist.end());  // Skip dist[0] (not used)
        
        return maxTime == INT_MAX ? -1 : maxTime;  // If there's an unreachable node, return -1
    }
};
