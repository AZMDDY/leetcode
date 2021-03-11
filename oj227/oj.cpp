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
        vector<int> stk;
        int num = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + static_cast<int>(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == (s.size() - 1)) {
                switch (sign) {
                    case '+': {
                        stk.push_back(num);
                    } break;
                    case '-': {
                        stk.push_back(-num);
                    } break;
                    case '*': {
                        stk.back() *= num;
                    } break;
                    case '/': {
                        stk.back() /= num;
                        break;
                    }
                }
                sign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};