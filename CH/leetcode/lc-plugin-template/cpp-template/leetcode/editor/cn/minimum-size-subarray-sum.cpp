/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30300
 *
 * [209] 长度最小的子数组
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
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int low = 0, sum = 0, fast = 0;
        int size = nums.size();
        int sub = 0;
        int res = __INT32_MAX__;
        for (size_t i = 0; i < size; i++)
        {
            /* code */
            sum += nums[i];
            while (sum >= target)
            {
                /* code */
                sub = (i - low + 1);
                res = res > sub ? sub : res;
                sum -= nums[low++];
            }
        }
        return res == __INT32_MAX__ ? 0 : res;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
    vector<int> v = {2, 3, 1, 2, 4, 3};
    solution.minSubArrayLen(7, v);
}

/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */
