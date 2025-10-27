/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30300
 *
 * [15] 三数之和
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 思路1： fff unordered_set duplicate
        // 思路2：fff ->unordered_map A+B->C 在 duplicate 如何不用duplicate？
        // 思路3：双指针
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                return res;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                /* code */
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    right--;
                    left++;
                }

                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }

                if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // sort: -4 -1 -1 0 1 2
    auto result = solution.threeSum(nums);
    for (const auto &triplet : result)
    {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]" << endl;
    }
}

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */
