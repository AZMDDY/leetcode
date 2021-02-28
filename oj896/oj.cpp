#include <vector>
#include <array>
#include <string>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A)
    {
        int pFlag = 0;
        int nFlag = 0;
        for (int i = 0; i < (A.size() - 1); i++) {
            if (A[i + 1] - A[i] >= 0) {
                pFlag++;
            }
            if (A[i + 1] - A[i] <= 0) {
                nFlag--;
            }
        }
        return abs(nFlag) == (A.size() - 1) || pFlag == (A.size() - 1);
    }
};