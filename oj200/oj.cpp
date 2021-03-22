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
    void dfs(vector<vector<char>>& gird, int row, int col, int m, int n)
    {
        if (row >= m || col >= n || row < 0 || col < 0 || gird[row][col] == '0') {
            return;
        }
        if (gird[row][col] == '1') {
            gird[row][col] = '-';
            dfs(gird, row + 1, col, m, n);
            dfs(gird, row, col + 1, m, n);
            dfs(gird, row, col - 1, m, n);
            dfs(gird, row - 1, col, m, n);
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};