#include <vector>
#include <array>
#include <string>
#include <numeric>
#include <unordered_map>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums)
    {
        prefixSums.assign(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) { return prefixSums[j + 1] - prefixSums[i]; }

private:
    vector<int> prefixSums;
};
