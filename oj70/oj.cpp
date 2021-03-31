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
    int climbStairs(int n) {
        int p1 = 0;
        int p2 = 0;
        int p3 = 1;
        for(int i = 1; i <= n; i++) {
            p1 = p2;
            p2 = p3;
            p3 = p1 + p2;
        }
        return p3;
    }
};