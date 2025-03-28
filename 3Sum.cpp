// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end()); // Sort the array

    for (int i = 0; i < nums.size(); ++i) {
        // Skip duplicate elements
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1; // Left pointer
        int right = nums.size() - 1; // Right pointer
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({ nums[i], nums[left], nums[right] });
                
                // Move both pointers and skip duplicates
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                
                left++;
                right--;
            } else if (sum < 0) {
                left++; // Increase sum by moving the left pointer
            } else {
                right--; // Decrease sum by moving the right pointer
            }
        }
    }

    return result;
}

void printTriplets(const std::vector<std::vector<int>>& triplets) {
    for (const auto& triplet : triplets) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    auto result1 = threeSum(nums1);
    std::cout << "Output for Example 1:\n";
    printTriplets(result1);

    std::vector<int> nums2 = {0, 1, 1};
    auto result2 = threeSum(nums2);
    std::cout << "Output for Example 2:\n";
    printTriplets(result2); // Output should be []

    std::vector<int> nums3 = {0, 0, 0};
    auto result3 = threeSum(nums3);
    std::cout << "Output for Example 3:\n";
    printTriplets(result3); // Output should be [[0,0,0]]

    return 0;
}