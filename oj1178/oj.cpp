#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
    {
        unordered_map<int, int> frequency;

        for (const string& word : words) {
            int mask = 0;
            for (char ch : word) {
                mask |= (1 << (ch - 'a'));
            }
            if (__builtin_popcount(mask) <= 7) {
                ++frequency[mask];
            }
        }

        vector<int> ans;
        for (const string& puzzle : puzzles) {
            int total = 0;

            for (int choose = 0; choose < (1 << 6); ++choose) {
                // 子集
                int mask = 0;
                for (int i = 0; i < 6; ++i) {
                    if (choose & (1 << i)) {
                        mask |= (1 << (puzzle[i + 1] - 'a'));
                    }
                }
                mask |= (1 << (puzzle[0] - 'a'));
                if (frequency.count(mask)) {
                    total += frequency[mask];
                }
            }
            ans.push_back(total);
        }
        return ans;
    }
};
