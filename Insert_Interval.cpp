// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval 
// and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping 
// intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.
// Note that you don't need to modify intervals in-place. You can make a new array and return it.


// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].



#include <iostream>
#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
    std::vector<std::vector<int>> result;
    int i = 0;
    int n = intervals.size();

    // 1. Add all intervals that end before the new interval starts
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }

    // 2. Merge intervals that overlap with newInterval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = std::min(newInterval[0], intervals[i][0]);
        newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        i++;
    }
    
    result.push_back(newInterval);  // Add the merged interval

    // 3. Add all the remaining intervals
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

void printIntervals(const std::vector<std::vector<int>>& intervals) {
    for (const auto& interval : intervals) {
        std::cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> intervals1 = {{1, 3}, {6, 9}};
    std::vector<int> newInterval1 = {2, 5};
    std::vector<std::vector<int>> result1 = insert(intervals1, newInterval1);
    std::cout << "Output: ";
    printIntervals(result1);  // Output: [[1, 5], [6, 9]]

    std::vector<std::vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    std::vector<int> newInterval2 = {4, 8};
    std::vector<std::vector<int>> result2 = insert(intervals2, newInterval2);
    std::cout << "Output: ";
    printIntervals(result2);  // Output: [[1, 2], [3, 10], [12, 16]]

    return 0;
}