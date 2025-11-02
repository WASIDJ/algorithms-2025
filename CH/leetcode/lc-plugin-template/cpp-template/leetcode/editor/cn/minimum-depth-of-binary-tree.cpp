/*
 * @lc app=leetcode.cn id=111 lang=cpp
 * @lcpr version=30300
 *
 * [111] 二叉树的最小深度
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
#include <cstdint>
#include <iostream>
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
  int getMinDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    // 如果是叶子节点，返回 1
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    int leftDepth = root->left ? getMinDepth(root->left) : INT16_MAX;
    int rightDepth = root->right ? getMinDepth(root->right) : INT16_MAX;
    int min = 1 + std::min(leftDepth, rightDepth);
    return min;
  }
  int minDepth(TreeNode *root) {
    // 迭代思路(推荐): 1. queue 发现叶子节点 就退出 (root->left == nullptr &&
    // root->right == nullptr)
    return getMinDepth(root);
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
// [2,null,3,null,4,null,5,null,6]\n
// @lcpr case=end

 */
