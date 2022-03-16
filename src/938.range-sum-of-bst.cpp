#include "stl_headers.hpp"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 */

// @lc code=start

class Solution {
  int low_, high_, rst{0};
 public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    low_ = low;
    high_ = high;
    BFS(root);
    return rst;
  }
  void BFS(TreeNode* n) {
    if (!n) return;
    if (n->val >= low_ && n->val <= high_) rst += n->val;
    BFS(n->left);
    BFS(n->right);
  }
};

// @lc code=end
