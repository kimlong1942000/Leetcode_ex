// Given a reference of a node in a connected undirected graph.
// Return a deep copy (clone) of the graph.
// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
// Test case format:

// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, 
// and so on. The graph is represented in the test case using an adjacency list.
// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

// Example 1:

// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// Example 2:

// Input: adjList = [[]]
// Output: [[]]
// Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
// Example 3:

// Input: adjList = []
// Output: []
// Explanation: This an empty graph, it does not have any nodes.
#include <iostream>
#include <vector>
#include <unordered_map>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    
    Node(int _val) : val(_val) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Handle the edge case where the input node is null
        if (node == nullptr) {
            return nullptr;
        }

        // HashMap to store the mapping of original nodes to cloned nodes
        std::unordered_map<Node*, Node*> cloneMap;

        // Start the DFS copy process
        return dfsClone(node, cloneMap);
    }

private:
    Node* dfsClone(Node* node, std::unordered_map<Node*, Node*>& cloneMap) {
        // If the node is already cloned, return the cloned node
        if (cloneMap.find(node) != cloneMap.end()) {
            return cloneMap[node];
        }

        // Clone the current node
        Node* clonedNode = new Node(node->val);
        cloneMap[node] = clonedNode; // Add to the map

        // Clone all the neighbors
        for (Node* neighbor : node->neighbors) {
            clonedNode->neighbors.push_back(dfsClone(neighbor, cloneMap));
        }

        return clonedNode;
    }
};

// Helper function to return a string representation of the graph for testing
void printGraph(Node* node) {
    if (node == nullptr) return;

    std::unordered_map<Node*, bool> visited;
    std::vector<Node*> stack = {node};

    while (!stack.empty()) {
        Node* curr = stack.back();
        stack.pop_back();

        if (visited[curr]) continue;
        visited[curr] = true;
        
        std::cout << "Node " << curr->val << ": ";
        for (Node* neighbor : curr->neighbors) {
            std::cout << neighbor->val << " ";
            if (!visited[neighbor]) {
                stack.push_back(neighbor);
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example 1
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution solution;
    Node* clonedGraph = solution.cloneGraph(node1);

    std::cout << "Original graph:\n";
    printGraph(node1);
    
    std::cout << "\nCloned graph:\n";
    printGraph(clonedGraph);

    // Cleanup
    delete node1, node2, node3, node4; // Free original nodes
    delete clonedGraph; // Free cloned graph - should implement destructor for deep cleanup

    return 0;
}