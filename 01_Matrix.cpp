// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two cells sharing a common edge is 1.

// Example 1:

// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:

// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]
 
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    // Directions for moving up, down, left, right
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Result matrix
    std::vector<std::vector<int>> distance(m, std::vector<int>(n, std::numeric_limits<int>::max()));
    std::queue<std::pair<int, int>> q;

    // Initialize the queue with all 0 cells and set their distance to 0
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                distance[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Perform a BFS
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            // Check boundaries
            if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                // If the neighboring cell can be updated with a shorter distance
                if (distance[newX][newY] > distance[x][y] + 1) {
                    distance[newX][newY] = distance[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }

    return distance;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<int>> mat1 = {{0,0,0}, {0,1,0}, {0,0,0}};
    std::vector<std::vector<int>> result1 = updateMatrix(mat1);
    std::cout << "Output for Example 1:\n";
    printMatrix(result1);

    std::vector<std::vector<int>> mat2 = {{0,0,0}, {0,1,0}, {1,1,1}};
    std::vector<std::vector<int>> result2 = updateMatrix(mat2);
    std::cout << "Output for Example 2:\n";
    printMatrix(result2);

    return 0;
}