#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
void traversal(TreeNode *cur, vector<int> &vec) {
  if (cur == nullptr) {
    return;
  }
  vec.push_back(cur->val);
  traversal(cur->left, vec);
  traversal(cur->right, vec);
}

// 前序遍历
void preorderTraversal(TreeNode *cur, vector<int> &vec) {
  if (cur == nullptr) {
    return;
  }
  vec.push_back(cur->val);            // 根
  preorderTraversal(cur->left, vec);  // 左
  preorderTraversal(cur->right, vec); // 右
}

// 中序遍历
void inorderTraversal(TreeNode *cur, vector<int> &vec) {
  if (cur == nullptr) {
    return;
  }
  inorderTraversal(cur->left, vec);  // 左
  vec.push_back(cur->val);           // 根
  inorderTraversal(cur->right, vec); // 右
}

// 后序遍历
void postorderTraversal(TreeNode *cur, vector<int> &vec) {
  if (cur == nullptr) {
    return;
  }
  postorderTraversal(cur->left, vec);  // 左
  postorderTraversal(cur->right, vec); // 右
  vec.push_back(cur->val);             // 根
}

int main() {
  // 构建示例二叉树：
  //       1
  //      / \
  //     2   3
  //    / \
  //   4   5
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  vector<int> vec;

  traversal(root, vec);
  cout << "traversal (generic): ";
  for (int v : vec)
    cout << v << ' ';
  cout << '\n';

  vec.clear();
  preorderTraversal(root, vec);
  cout << "preorder: ";
  for (int v : vec)
    cout << v << ' ';
  cout << '\n';

  vec.clear();
  inorderTraversal(root, vec);
  cout << "inorder: ";
  for (int v : vec)
    cout << v << ' ';
  cout << '\n';

  vec.clear();
  postorderTraversal(root, vec);
  cout << "postorder: ";
  for (int v : vec)
    cout << v << ' ';
  cout << '\n';

  // 释放内存
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;
  return 0;
}