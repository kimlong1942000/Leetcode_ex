// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
#include <iostream>
#include <vector>
#include <stack> // For DFS

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) return 0;

        int numRows = grid.size();
        int numCols = grid[0].size();
        int islandCount = 0;

        // Iterate through each cell in the grid
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] == '1') { // Found an island
                    islandCount++;
                    // Perform DFS to mark the entire island
                    markIsland(grid, i, j);
                }
            }
        }

        return islandCount;
    }

private:
    void markIsland(std::vector<std::vector<char>>& grid, int row, int col) {
        // Base condition to check bounds
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') {
            return;
        }

        // Mark the land cell as visited
        grid[row][col] = '0';

        // Explore all four directions
        markIsland(grid, row + 1, col); // Down
        markIsland(grid, row - 1, col); // Up
        markIsland(grid, row, col + 1); // Right
        markIsland(grid, row, col - 1); // Left
    }
};

int main() {
    Solution solution;

    std::vector<std::vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    
    std::cout << "Number of islands: " << solution.numIslands(grid1) << std::endl; // Output: 1

    std::vector<std::vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    std::cout << "Number of islands: " << solution.numIslands(grid2) << std::endl; // Output: 3

    return 0;
}