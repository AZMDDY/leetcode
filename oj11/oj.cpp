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
    int maxArea(vector<int>& height)
    {
        int right = 0;
        int left = height.size() - 1;
        int area = 0;
        int maxArea = 0;
        while (right < left) {
            area = (left - right) * min(height[right], height[left]);
            if (area > maxArea) {
                maxArea = area;
            }
            if (height[right] < height[left]) {
                right++;
            } else if (height[right] > height[left]) {
                left--;
            } else {
                right++;
                left--;
            }
        }
        return maxArea;
    }
};