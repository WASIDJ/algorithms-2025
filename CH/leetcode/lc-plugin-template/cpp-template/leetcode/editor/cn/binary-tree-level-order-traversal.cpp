/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30300
 *
 * [102] 二叉树的层序遍历
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      vector<int> mid;
      for (int i = 0; i < size; i++) {
        TreeNode *cur = q.front(); // 时刻记得 对 item 进行 pop!!!
        q.pop();
        mid.push_back(cur->val);
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
      res.push_back(mid);
    }
    return res;
  }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
