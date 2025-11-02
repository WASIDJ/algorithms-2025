/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30300
 *
 * [101] 对称二叉树
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <cstddef>
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
  bool compare(TreeNode *left, TreeNode *right) {
    if (left == NULL && right != NULL) {
      return false;
    } else if (left != NULL && right == NULL) {
      return false;
    } else if (left == NULL && right == NULL) {
      return true;
    } else if (left->val != right->val) {
      return false;
    }

    bool out = compare(left->left, right->right);
    bool in = compare(left->right, right->left);
    bool isSame = out && in;
    return isSame;
  }

  bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty()) {
      TreeNode *leftNode = q.front();
      q.pop();
      TreeNode *rightNode = q.front();
      q.pop();

      // 判断
      if (!leftNode && !rightNode) {
        continue;
      } else if (!leftNode || !rightNode || (leftNode->val != rightNode->val)) {
        return false;
      }

      // 迭代
      q.push(leftNode->left);
      q.push(rightNode->right);
      q.push(leftNode->right);
      q.push(rightNode->left);
    }
    return true;
    // 思路 一: 两个子树 数列是否相同 ?
    // 迭代 层次
    // 递归
    // 主要思路: in out 比较
  }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}

/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */
