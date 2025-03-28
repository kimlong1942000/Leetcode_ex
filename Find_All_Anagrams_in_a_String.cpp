// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;
        int sLen = s.length();
        int pLen = p.length();

        if (sLen < pLen) return result; // Return if s is shorter than p

        // Frequency map for characters in p
        std::unordered_map<char, int> pCount;
        for (char c : p) {
            pCount[c]++;
        }

        // Frequency map for the current window in s
        std::unordered_map<char, int> sCount;

        // Initial window in s
        for (int i = 0; i < pLen; i++) {
            sCount[s[i]]++;
        }

        // Check if the first window is an anagram
        if (sCount == pCount) {
            result.push_back(0);
        }

        // Sliding the window over s
        for (int i = pLen; i < sLen; i++) {
            // Include the new character into the window
            sCount[s[i]]++;
            // Remove the leftmost character from the window
            sCount[s[i - pLen]]--;

            // If the count becomes zero, remove it from the map
            if (sCount[s[i - pLen]] == 0) {
                sCount.erase(s[i - pLen]);
            }

            // Check if current window's count matches p's count
            if (sCount == pCount) {
                result.push_back(i - pLen + 1);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    std::string s1 = "cbaebabacd";
    std::string p1 = "abc";
    auto result1 = solution.findAnagrams(s1, p1);
    std::cout << "Anagram indices for s1: ";
    for (int index : result1) {
        std::cout << index << " ";
    }
    std::cout << std::endl; // Output: [0, 6]

    std::string s2 = "abab";
    std::string p2 = "ab";
    auto result2 = solution.findAnagrams(s2, p2);
    std::cout << "Anagram indices for s2: ";
    for (int index : result2) {
        std::cout << index << " ";
    }
    std::cout << std::endl; // Output: [0, 1, 2]

    return 0;
}