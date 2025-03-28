// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) return result; // Return empty if tree is empty

    std::queue<TreeNode*> q; // Queue for level order traversal
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level
        std::vector<int> currentLevel; // To hold values of the current level

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val); // Add node value to current level

            // Enqueue left and right children if they exist
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(currentLevel); // Add current level to the result
    }

    return result;
}

// Function to assist in building the tree (for testing)
TreeNode* buildTree(std::vector<std::string> values) {
    if (values.empty() || values[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(values[0]));
    std::queue<TreeNode*> queue;
    queue.push(root);

    for (size_t i = 1; i < values.size(); i++) {
        TreeNode* current = queue.front();
        queue.pop();

        if (values[i] != "null") {
            current->left = new TreeNode(stoi(values[i]));
            queue.push(current->left);
        }
        if (++i < values.size() && values[i] != "null") {
            current->right = new TreeNode(stoi(values[i]));
            queue.push(current->right);
        }
    }

    return root;
}

// Function to print the result neatly
void printLevelOrder(const std::vector<std::vector<int>>& levels) {
    for (const auto& level : levels) {
        std::cout << "[";
        for (size_t i = 0; i < level.size(); i++) {
            std::cout << level[i];
            if (i != level.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }
}

int main() {
    std::vector<std::string> input1 = {"3", "9", "20", "null", "null", "15", "7"};
    TreeNode* root1 = buildTree(input1);
    auto result1 = levelOrder(root1);
    std::cout << "Output for Example 1:\n";
    printLevelOrder(result1);

    std::vector<std::string> input2 = {"1"};
    TreeNode* root2 = buildTree(input2);
    auto result2 = levelOrder(root2);
    std::cout << "Output for Example 2:\n";
    printLevelOrder(result2);

    std::vector<std::string> input3 = {};
    TreeNode* root3 = buildTree(input3);
    auto result3 = levelOrder(root3);
    std::cout << "Output for Example 3:\n";
    printLevelOrder(result3);

    return 0;
}