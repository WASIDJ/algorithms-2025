/*
 * @lc app=leetcode.cn id=349 lang=cpp
 * @lcpr version=30300
 *
 * [349] 两个数组的交集
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 思路1：for for
        // 思路2：转unordered_set
        unordered_set<int> res;
        unordered_set<int> arr{nums1.begin(), nums1.end()};
        for (int num : nums2)
        {
            if (arr.find(num) != arr.end())
            {
                res.insert(num);
            }
        }
        return vector<int>{res.begin(), res.end()};
        // 思路3：如何设置 hashfunc
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
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */
