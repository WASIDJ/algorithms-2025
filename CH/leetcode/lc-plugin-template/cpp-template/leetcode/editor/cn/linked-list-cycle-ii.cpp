/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30300
 *
 * [142] 环形链表 II
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 更好的编码规范，少花括号
        // 思路1 ： map 地址 如果存在 就返回 改地址
        // 思路2： 龟兔赛跑
        ListNode *low = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            low = low->next;
            fast = fast->next->next;
            if (fast == low)
                break;
        }
        if (!fast || !fast->next)
            return nullptr;
        ListNode *cur = head;
        while (cur != fast)
        {
            /* code */
            cur = cur->next;
            fast = fast->next;
        }
        return cur;
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
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */
