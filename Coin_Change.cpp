// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0

#include <iostream>
#include <vector>
#include <limits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        // Initialize DP array
        std::vector<int> dp(amount + 1, amount + 1);
        
        // Base case: Zero amount requires zero coins
        dp[0] = 0;

        // Fill the DP array
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }

        // Check if we can form the amount
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};

int main() {
    Solution solution;

    std::vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    std::cout << "Output for coins1: " << solution.coinChange(coins1, amount1) << std::endl; // Output: 3

    std::vector<int> coins2 = {2};
    int amount2 = 3;
    std::cout << "Output for coins2: " << solution.coinChange(coins2, amount2) << std::endl; // Output: -1

    std::vector<int> coins3 = {1};
    int amount3 = 0;
    std::cout << "Output for coins3: " << solution.coinChange(coins3, amount3) << std::endl; // Output: 0

    return 0;
}