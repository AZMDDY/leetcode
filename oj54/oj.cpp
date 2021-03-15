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
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> ans;
        if (matrix.empty()) {
            return ans;
        }
        int upLimit = 0;
        int downLimit = matrix.size() - 1;
        int leftLimit = 0;
        int rightLimit = matrix[0].size() - 1;
        while (true) {
            for (int i = leftLimit; i <= rightLimit; i++) {
                ans.push_back(matrix[upLimit][i]);
            }
            if (++upLimit > downLimit) {
                break;
            }
            for (int i = upLimit; i <= downLimit; i++) {
                ans.push_back(matrix[i][rightLimit]);
            }
            if (--rightLimit < leftLimit) {
                break;
            }
            for (int i = rightLimit; i >= leftLimit; i--) {
                ans.push_back(matrix[downLimit][i]);
            }
            if (--downLimit < upLimit) {
                break;
            }
            for (int i = downLimit; i >= upLimit; i--) {
                ans.push_back(matrix[i][leftLimit]);
            }
            if (++leftLimit > rightLimit) {
                break;
            }
        }
        return ans;
    }
};