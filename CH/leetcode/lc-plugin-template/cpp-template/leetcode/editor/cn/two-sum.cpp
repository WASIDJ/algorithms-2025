/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30300
 *
 * [1] 两数之和
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 思路1：map
        unordered_map<int, int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            /* code */
            auto item = res.find(target - nums[i]);
            if (item != res.end())
            {
                /* code */
                return {item->second, i};
            }

            res.insert(pair<int, int>{nums[i], i});
        }
        return {};
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
