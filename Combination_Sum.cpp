// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentCombination;
        backtrack(result, currentCombination, candidates, target, 0);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& currentCombination,
                   std::vector<int>& candidates, int target, int startIndex) {
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }

        if (target < 0) {
            return; // Terminate if the current combination exceeds the target
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            currentCombination.push_back(candidates[i]); // Choose the current candidate
            backtrack(result, currentCombination, candidates, target - candidates[i], i); // We can reuse the same candidate
            currentCombination.pop_back(); // Backtrack and remove the last candidate
        }
    }
};

int main() {
    Solution solution;

    std::vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    auto result1 = solution.combinationSum(candidates1, target1);
    std::cout << "Output for candidates1: ";
    for (const auto& combination : result1) {
        std::cout << "[";
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;

    std::vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    auto result2 = solution.combinationSum(candidates2, target2);
    std::cout << "Output for candidates2: ";
    for (const auto& combination : result2) {
        std::cout << "[";
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;

    std::vector<int> candidates3 = {2};
    int target3 = 1;
    auto result3 = solution.combinationSum(candidates3, target3);
    std::cout << "Output for candidates3: ";
    for (const auto& combination : result3) {
        std::cout << "[";
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;

    return 0;
}