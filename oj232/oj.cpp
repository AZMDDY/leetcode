#include <vector>
#include <array>
#include <string>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { inStk.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (outStk.empty()) {
            in2out();
        }
        int ans = outStk.top();
        outStk.pop();
        return ans;
    }

    /** Get the front element. */
    int peek()
    {
        if (outStk.empty()) {
            in2out();
        }
        return outStk.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return inStk.empty() && outStk.empty(); }

private:
    stack<int> inStk;
    stack<int> outStk;

    void in2out()
    {
        while (!inStk.empty()) {
            outStk.push(inStk.top());
            inStk.pop();
        }
    }
};