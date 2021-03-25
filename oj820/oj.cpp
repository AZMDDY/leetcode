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
    int minimumLengthEncoding(vector<string>& words)
    {
        for (auto& w : words) {
            reverse(w.begin(), w.end());
        }
        sort(words.begin(), words.end());
        int ans = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            int size = words[i].size();
            if (words[i] == words[i + 1].substr(0, size)) {
                continue;
            }
            ans += size + 1;
        }
        return ans + words.back().size() + 1;
    }
};