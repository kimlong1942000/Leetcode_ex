// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

#include <iostream>
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        // Create an adjacency list to represent the graph
        std::vector<std::vector<int>> graph(numCourses);
        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
        
        // Create a visited state array:
        // 0 = unvisited, 1 = visiting, 2 = visited
        std::vector<int> visited(numCourses, 0);
        
        // Check each course
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(graph, i, visited)) {
                return false; // Cycle detected
            }
        }
        
        return true; // No cycles found
    }

private:
    bool hasCycle(const std::vector<std::vector<int>>& graph, int node, std::vector<int>& visited) {
        // If the node is currently being visited, we found a cycle
        if (visited[node] == 1) {
            return true;
        }
        
        // If the node has already been visited, no need to check again
        if (visited[node] == 2) {
            return false;
        }
        
        // Mark the node as visiting
        visited[node] = 1;
        
        // Visit all the neighbors of the current node
        for (const auto& neighbor : graph[node]) {
            if (hasCycle(graph, neighbor, visited)) {
                return true; // Cycle found
            }
        }
        
        // Mark the node as completely visited
        visited[node] = 2;
        return false; // No cycle found
    }
};

int main() {
    Solution solution;

    int numCourses1 = 2;
    std::vector<std::vector<int>> prerequisites1 = {{1, 0}};
    std::cout << "Output for numCourses1: " << (solution.canFinish(numCourses1, prerequisites1) ? "true" : "false") << std::endl; // Output: true

    int numCourses2 = 2;
    std::vector<std::vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    std::cout << "Output for numCourses2: " << (solution.canFinish(numCourses2, prerequisites2) ? "true" : "false") << std::endl; // Output: false

    return 0;
}