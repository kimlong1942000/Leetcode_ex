// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> results; // To store all permutations
        backtrack(results, nums, 0); // Start backtracking from index 0
        return results;
    }

private:
    void backtrack(std::vector<std::vector<int>>& results, std::vector<int>& nums, int start) {
        // Base case: if the current index is at the end, we have a complete permutation
        if (start == nums.size()) {
            results.push_back(nums); // Add the current permutation to the results
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            std::swap(nums[start], nums[i]); // Swap the current element to fix it
            backtrack(results, nums, start + 1); // Recurse to the next index
            std::swap(nums[start], nums[i]); // Swap back to backtrack
        }
    }
};

int main() {
    Solution solution;

    std::vector<int> nums1 = {1, 2, 3};
    auto result1 = solution.permute(nums1);
    std::cout << "Permutations for nums1: " << std::endl;
    for (const auto& perm : result1) {
        std::cout << "[";
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    std::vector<int> nums2 = {0, 1};
    auto result2 = solution.permute(nums2);
    std::cout << "Permutations for nums2: " << std::endl;
    for (const auto& perm : result2) {
        std::cout << "[";
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    std::vector<int> nums3 = {1};
    auto result3 = solution.permute(nums3);
    std::cout << "Permutations for nums3: " << std::endl;
    for (const auto& perm : result3) {
        std::cout << "[";
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}