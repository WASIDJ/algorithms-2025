/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30300
 *
 * [242] 有效的字母异位词
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
    bool isAnagram(string s, string t)
    {
        int record[26] = {0};
        for (size_t i = 0; i < s.size(); i++)
        {
            /* code */
            record[s[i] - 'a'] += 1;
        }

        for (size_t i = 0; i < t.size(); i++)
        {
            /* code */
            record[t[i] - 'a'] -= 1;
        }

        for (size_t i = 0; i < 26; i++)
        {
            /* code */
            if (record[i] != 0)
            {
                return false;
            }
        }
        return true;
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
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */
