/*
 * @lc app=leetcode.cn id=454 lang=cpp
 * @lcpr version=30300
 *
 * [454] 四数相加 II
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
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        // 矩阵求rank X python的话会飞快
        // unordered_map
        unordered_map<int, int> hashMap;
        for (int a : nums1)
        {
            for (auto b : nums2)
            {
                hashMap[a + b]++;
            }
        }

        int res = 0;
        for (int c : nums3)
        {
            for (auto d : nums4)
            {
                if (hashMap.find(-(c + d)) != hashMap.end())
                {
                    /* code */
                    res += hashMap[-(c + d)];
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
}

/*
// @lcpr case=start
// [1,2]\n[-2,-1]\n[-1,2]\n[0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n[0]\n[0]\n
// @lcpr case=end

 */
