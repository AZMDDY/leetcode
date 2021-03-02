#include <vector>
#include <array>
#include <string>
#include <numeric>
#include <unordered_map>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) {
            return;
        }
        prefixMatrix = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                prefixMatrix[i][j + 1] = prefixMatrix[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (prefixMatrix.empty()) {
            return 0;
        }

        int ans = 0;
        for (int i = row1; i <= row2; i++) {
            ans += prefixMatrix[i][col2 + 1] - prefixMatrix[i][col1];
        }
        return ans;
    }

private:
    vector<vector<int>> prefixMatrix;
};
