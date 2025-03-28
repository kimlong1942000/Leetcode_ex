// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

 

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

#include <iostream>
#include <stack>
#include <limits>

class MinStack {
private:
    std::stack<int> mainStack; // To store all elements
    std::stack<int> minStack;   // To store minimum elements

public:
    /** Initialize your data structure here. */
    MinStack() {
    }

    void push(int val) {
        mainStack.push(val);
        // Push onto minStack if it's empty or the current value is <= the current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop(); // Also pop from minStack if we are removing the minimum element
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    std::cout << "Minimum: " << minStack.getMin() << std::endl;   // Returns -3
    minStack.pop();
    std::cout << "Top: " << minStack.top() << std::endl;          // Returns 0
    std::cout << "Minimum: " << minStack.getMin() << std::endl;   // Returns -2

    return 0;
}
 