class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Step 1: Create a graph, where the key is the airport and the value is a list of destinations
        unordered_map<string, multiset<string>> graph;
        
        // Step 2: Build the graph by inserting each ticket into the graph
        for (const auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        
        vector<string> itinerary;
        // Step 3: Perform DFS starting from "JFK"
        dfs(graph, "JFK", itinerary);
        
        // Step 4: Reverse the itinerary because we need to add airports in reverse order
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
    
private:
    // Helper function to perform DFS
    void dfs(unordered_map<string, multiset<string>>& graph, const string& airport, vector<string>& itinerary) {
        // While there are destinations left for the current airport
        while (!graph[airport].empty()) {
            // Get the next destination (smallest lexicographically)
            string next = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());  // Remove the ticket
            dfs(graph, next, itinerary);  // Recurse for the next airport
        }
        
        // Once no more destinations, add the current airport to the itinerary
        itinerary.push_back(airport);
    }
};
