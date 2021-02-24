#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
    {
        for (auto& row : A) {
            for (int i = 0; i < (row.size() + 1) / 2; i++) {
                if (row[i] == row[row.size() - i - 1]) {
                    row[i] = row[row.size() - i - 1] = 1 - row[i];
                }
            }
        }
        return A;
    }
};