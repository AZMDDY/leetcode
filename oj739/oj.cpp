#include <vector>
#include <array>
#include <string>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        int n = T.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                int preIndex = stk.top();
                ans[preIndex] = i - preIndex;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};