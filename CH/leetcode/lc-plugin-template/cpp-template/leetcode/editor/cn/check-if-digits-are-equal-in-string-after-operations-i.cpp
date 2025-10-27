/*
 * @lc app=leetcode.cn id=3461 lang=cpp
 * @lcpr version=30300
 *
 * [3461] 判断操作后字符串中的数字是否相等 I
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    bool hasSameDigits(string s)
    {
        int size = s.size();
        vector<int> res(size);
        for (size_t i = 0; i < size; i++)
        {
            res[i] = s[i] - '0';
        }
        while (res.size() > 2)
        {
            int m = res.size();
            vector<int> temp(m - 1);
            for (size_t i = 0; i < m - 1; i++)
            {
                temp[i] = (res[i] + res[i + 1]) % 10;
            }
            res.swap(temp);
        }
        return res[0] == res[1];
    }
};
// @lc code=end

int main()
{
    Solution solution;
    solution.hasSameDigits("3902");
}

/*
// @lcpr case=start
// "3902"\n
// @lcpr case=end

// @lcpr case=start
// "34789"\n
// @lcpr case=end

 */
