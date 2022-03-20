#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

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
  int diameterOfBinaryTree(TreeNode* root) { return diameter(root); }

  int diameter(TreeNode* root) {
    if (!root) return 0;
    return max({diameter(root->left), diameter(root->right),
                max_depth(root->left) + max_depth(root->right) + 2});
  }

  int max_depth(TreeNode* root) {
    if (!root) return -1;
    return max(max_depth(root->left), max_depth(root->right)) + 1;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> v{1, 2, 3, 4, 5};
  auto root = build_tree<TreeNode>(v);
  s.diameterOfBinaryTree(root);
  return 0;
}