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
    int maxSubArray(vector<int>& nums)
    {
        int pre = 0;
        int maxAns = nums[0];
        for (auto& n : nums) {
            pre = max(pre + n, n);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};
