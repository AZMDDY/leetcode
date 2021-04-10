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
    string largestNumber(vector<int>& nums)
    {
        vector<string> numsStr;
        for (auto num : nums) {
            numsStr.push_back(to_string(num));
        }
        sort(numsStr.begin(), numsStr.end());
        
    }
};