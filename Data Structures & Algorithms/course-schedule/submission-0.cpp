class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
                // Step 1: Create an adjacency list to represent the graph
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Build the graph and calculate in-degree
        for (const auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int preReq = prerequisite[1];
            adj[preReq].push_back(course);
            inDegree[course]++;
        }

        // Step 2: Use a queue to store courses with zero in-degree
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Process the courses in the queue
        int processedCourses = 0;
        while (!q.empty()) {
            int currentCourse = q.front();
            q.pop();
            processedCourses++;

            // Reduce the in-degree of the neighbors
            for (int neighbor : adj[currentCourse]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: If the number of processed courses is equal to numCourses, it's possible to finish all courses
        return processedCourses == numCourses;
    }
};
