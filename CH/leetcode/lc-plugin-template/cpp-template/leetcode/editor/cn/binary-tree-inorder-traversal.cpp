/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30300
 *
 * [94] 二叉树的中序遍历
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    // 终止条件 当前为 cur 要么 stack 空了
    while (cur != NULL || !st.empty()) {
      if (cur != NULL) {
        st.push(cur);
        cur = cur->left;
      } else {
        cur = st.top();
        st.pop();
        res.push_back(cur->val);
        cur = cur->right;
      }
    }
    return res;
  }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
  // 示例 1: [1,null,2,3]
  TreeNode *t1 = new TreeNode(1);
  t1->right = new TreeNode(2);
  t1->right->left = new TreeNode(3);
  vector<int> r1 = solution.inorderTraversal(t1);
  cout << "case1: [";
  for (size_t i = 0; i < r1.size(); ++i) {
    if (i)
      cout << ",";
    cout << r1[i];
  }
  cout << "]\n";

  // 示例 2: []
  TreeNode *t2 = nullptr;
  vector<int> r2 = solution.inorderTraversal(t2);
  cout << "case2: [";
  for (size_t i = 0; i < r2.size(); ++i) {
    if (i)
      cout << ",";
    cout << r2[i];
  }
  cout << "]\n";

  // 示例 3: [1]
  TreeNode *t3 = new TreeNode(1);
  vector<int> r3 = solution.inorderTraversal(t3);
  cout << "case3: [";
  for (size_t i = 0; i < r3.size(); ++i) {
    if (i)
      cout << ",";
    cout << r3[i];
  }
  cout << "]\n";

  // 释放内存
  delete t1->right->left;
  delete t1->right;
  delete t1;
  delete t3;
}
/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
