class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Create the graph (adjacency list) and in-degree array
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        // Step 2: Build the graph and calculate the in-degree for each course
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int preReq = prereq[1];
            adj[preReq].push_back(course); // Edge from preReq to course
            inDegree[course]++; // Increment the in-degree for the course
        }

        // Step 3: Use a queue to process courses with zero in-degree
        queue<int> q;
        vector<int> result;
        
        // Enqueue courses with no prerequisites (in-degree == 0)
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: Process courses from the queue
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);

            // Decrease the in-degree of all dependent courses
            for (int neighbor : adj[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the number of courses in the result is equal to numCourses, we found a valid order
        if (result.size() == numCourses) {
            return result;
        }
        
        // If we couldn't process all courses, return an empty vector (cycle detected)
        return {};
    }
};
