// Given a string s, find the length of the longest substring without duplicate characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <iostream>
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> charIndex; // To store the last index of each character
    int maxLength = 0; // To track the maximum length of substring found
    int start = 0; // Left pointer of the sliding window

    for (int end = 0; end < s.size(); ++end) {
        // If the character at `end` already exists in the current substring
        if (charIndex.find(s[end]) != charIndex.end() && charIndex[s[end]] >= start) {
            // Move the start pointer to the right of the last occurrence of s[end]
            start = charIndex[s[end]] + 1;
        }

        // Update the last seen index of the character
        charIndex[s[end]] = end;

        // Calculate the length of the current substring and update maxLength
        maxLength = std::max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    std::string s1 = "abcabcbb";
    std::string s2 = "bbbbb";
    std::string s3 = "pwwkew";

    std::cout << "Output for '" << s1 << "': " << lengthOfLongestSubstring(s1) << std::endl; // Output: 3
    std::cout << "Output for '" << s2 << "': " << lengthOfLongestSubstring(s2) << std::endl; // Output: 1
    std::cout << "Output for '" << s3 << "': " << lengthOfLongestSubstring(s3) << std::endl; // Output: 3

    return 0;
}