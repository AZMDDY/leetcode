#include <vector>
#include <array>
#include <string>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <unordered_map>

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
    int leastBricks(vector<vector<int>>& wall)
    {
        unordered_map<int, int> m;
        for (auto& row : wall) {
            int sum = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                m[sum]++;
            }
        }
        int maxCount = 0;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            maxCount = max(maxCount, iter->second);
        }
        return wall.size() - maxCount;
    }
};