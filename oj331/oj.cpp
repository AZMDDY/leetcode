#include <vector>
#include <array>
#include <string>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder)
    {
        int n = preorder.size();
        int ans = 1;
        if (n == 0 || preorder[0] == '#') {
            return n <= 1;
        }
        for (int i = 1; i < n - 1; i++) {
            if (preorder[i] == ',') {
                if (preorder[i + 1] != '#') {
                    ans++;
                } else {
                    ans--;
                }
            }
            // 先遍历的非叶子节点总比叶子节点多
            if (ans < 0 && i != (n - 2)) {
                return false;
            }
        }
        return ans == -1;
    }
};