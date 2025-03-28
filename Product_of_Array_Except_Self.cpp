// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, 1); // Initialize the answer array with 1

        // Calculate prefix products
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        // Calculate suffix products and update the answer array
        int suffixProduct = 1; // Initialize suffix product
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffixProduct;   // Multiply with the current suffix product
            suffixProduct *= nums[i];      // Update the suffix product
        }

        return answer;
    }
};

int main() {
    Solution solution;

    std::vector<int> nums1 = {1, 2, 3, 4};
    std::vector<int> result1 = solution.productExceptSelf(nums1);
    std::cout << "Output for nums1: ";
    for (int value : result1) {
        std::cout << value << " ";
    }
    std::cout << std::endl; // Output: [24, 12, 8, 6]

    std::vector<int> nums2 = {-1, 1, 0, -3, 3};
    std::vector<int> result2 = solution.productExceptSelf(nums2);
    std::cout << "Output for nums2: ";
    for (int value : result2) {
        std::cout << value << " ";
    }
    std::cout << std::endl; // Output: [0, 0, 9, 0, 0]

    return 0;
}