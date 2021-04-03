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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
    {
        vector<int> ans(n, 0);
        for (auto& book : bookings) {
            ans[book[0] - 1] += book[2];
            if (book[1] < n) {
                ans[book[1]] -= book[2];
            }
        }
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + ans[i];
        }
        return ans;
    }
};