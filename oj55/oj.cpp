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
    bool canJump(vector<int>& nums)
    {
        int maxIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= maxIdx) {
                maxIdx = max(i + nums[i], maxIdx);
                if (maxIdx >= nums.size() - 1) {
                    return true;
                }
            } else {
                return false;
            }
        }
        return false;
    }
};