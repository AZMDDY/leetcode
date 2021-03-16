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
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int left = 0;
        int right = n - 1;
        int up = 0;
        int down = n - 1;
        int num = 1;
        int target = n * n;
        while (num <= target) {
            for (int i = left; i <= right; i++) {
                matrix[up][i] = num++;
            }
            up++;
            for (int i = up; i <= down; i++) {
                matrix[i][right] = num++;
            }
            right--;
            for (int i = right; i >= left; i--) {
                matrix[down][i] = num++;
            }
            down--;
            for (int i = down; i >= up; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
        return matrix;
    }
};