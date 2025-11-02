#include <cstddef>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {

public:
  struct Tree {
    int val;
    Tree *left;
    Tree *right;
    Tree(int val) : val(val), left(nullptr), right(nullptr) {}
  };
  // 我懂了
  vector<int> inorderTraversal(Tree *root) {
    vector<int> res;
    stack<Tree *> st;
    if (root != NULL) {
      st.push(root);
    }
    while (!st.empty()) {
      Tree *node = st.top();
      if (node != NULL) {
        // 这个是用来干什么的? 下一层的
        st.pop();
        if (node->right)
          st.push(node->right);
        // 通用模板 你只需要 理解 这两行 的位置代码意义
        st.push(node);
        st.push(NULL); // 我不理解为什么要有这个? 表示是否被处理
        if (node->left)
          st.push(node->left);
      } else {
        st.pop();
        node = st.top();
        st.pop();
        res.push_back(node->val);
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  Solution::Tree *root = new Solution::Tree(1);
  root->left = new Solution::Tree(2);
  root->right = new Solution::Tree(3);
  root->left->left = new Solution::Tree(4);

  std::vector<int> result = sol.inorderTraversal(root);
  for (int v : result)
    std::cout << v << ' ';
  std::cout << std::endl;

  // cleanup
  delete root->left->left;
  delete root->left;
  delete root->right;
  delete root;
  return 0;
}