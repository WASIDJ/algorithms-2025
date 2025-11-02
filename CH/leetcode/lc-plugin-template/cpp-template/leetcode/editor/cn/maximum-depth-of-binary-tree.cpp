/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30300
 *
 * [104] 二叉树的最大深度
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
#include <iostream>
#include <queue>
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
  int getDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    int depth = 1 + max(leftDepth, rightDepth);
    return depth;
  }
  int maxDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int depth = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
      depth++;
    }
    return depth;
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
// [1,null,2]\n
// @lcpr case=end

 */
