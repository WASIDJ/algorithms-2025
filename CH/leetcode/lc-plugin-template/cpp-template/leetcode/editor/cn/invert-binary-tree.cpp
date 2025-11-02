/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=30300
 *
 * [226] 翻转二叉树
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
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
  TreeNode *invertTree(TreeNode *root) {
    // 思路 一: 左右 Node 替换一下 适合递归
    if (root == nullptr) {
      return root;
    }
    TreeNode *cur = root;
    TreeNode *tmp = cur->left;
    cur->left = cur->right;
    cur->right = tmp;
    invertTree(cur->left); // 这个位置有没有关系
    invertTree(cur->right);
    return root;
  }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}

/*
// @lcpr case=start
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
