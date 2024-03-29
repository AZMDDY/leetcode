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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* p = new ListNode(-1, head);
        ListNode* pre = p;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        ListNode* next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        ListNode* ans = p->next;
        delete p;
        return ans;
    }
};
