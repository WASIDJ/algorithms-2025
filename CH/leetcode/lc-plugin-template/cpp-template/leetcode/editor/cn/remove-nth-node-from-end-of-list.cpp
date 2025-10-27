/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30300
 *
 * [19] 删除链表的倒数第 N 个结点
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode *low = dummyhead;
        ListNode *fast = dummyhead;
        for (size_t i = 0; i < n + 1; i++)
        {
            fast = fast->next;
        }
        while (fast)
        {
            low = low->next;
            fast = fast->next;
        }
        ListNode *tmp = low->next;
        low->next = low->next->next;
        delete tmp;
        return dummyhead->next;
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
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
