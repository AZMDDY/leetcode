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
    string removeDuplicates(string S)
    {
        string ans;
        for (char chr : S) {
            if (!ans.empty() && ans.back() == chr) {
                ans.pop_back();
            } else {
                ans.push_back(chr);
            }
        }
        return ans;
    }
};