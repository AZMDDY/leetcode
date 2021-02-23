#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
    {
        int len = customers.size();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }
        int cut = 0;
        for (int i = 0; i < X; i++) {
            cut += customers[i] * grumpy[i];
        }
        int maxCut = cut;
        for (int i = X; i < len; i++) {
            cut = cut - customers[i - X] * grumpy[i - X] + customers[i] * grumpy[i];
            maxCut = std::max(maxCut, cut);
        }
        return sum + maxCut;
    }
};