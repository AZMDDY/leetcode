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
    int calculate(string s)
    {
        stack<int> sign;
        sign.push(1);
        int ans = 0;
        int num = 0;
        int op = 1;
        for (auto& chr : s) {
            if (chr >= '0' && chr <= '9') {
                num = num * 10 + (chr - '0');
                continue;
            }
            ans += op * num;
            num = 0;
            if (chr == '+') {
                op = sign.top();
            } else if (chr == '-') {
                op = -sign.top();
            } else if (chr == '(') {
                sign.push(op);
            } else if (chr == ')') {
                sign.pop();
            }
        }
        return ans + op * num;
    }
};