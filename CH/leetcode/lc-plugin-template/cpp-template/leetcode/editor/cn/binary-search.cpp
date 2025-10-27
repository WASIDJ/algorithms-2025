/*
 * @lc app=leetcode.cn id=704 lang=cpp
 * @lcpr version=30300
 *
 * [704] 二分查找
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
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int guess = (low + high) / 2;
            if (nums[guess] < target)
            {
                low += 1;
            }
            else if (nums[guess] > target)
            {
                high -= 1;
            }
            else
            {
                return guess;
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
    vector<int> nums = {5};
    solution.search(nums, 5);
}

/*
// @lcpr case=start
// [-1,0,3,5,9,12]\n9\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,3,5,9,12]\n2\n
// @lcpr case=end

 */
