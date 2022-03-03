#include "stl_headers.hpp"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * @lc app=leetcode id=1644 lang=cpp
 *
 * [1644] Lowest Common Ancestor of a Binary Tree II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    auto lp = move(lineage(root, p)), lq = move(lineage(root, q));
    if (lp.empty() || lq.empty()) return nullptr;
    TreeNode* rst = root;
    for (int i = 0; i < min(lp.size(), lq.size()); ++i)
      if (lp[lp.size() - 1 - i] == lq[lq.size() - 1 - i])
        rst = lq[lq.size() - 1 - i];
      else
        break;
    return rst;
  }
  vector<TreeNode*> lineage(TreeNode* root, TreeNode* p) {
    vector<TreeNode*> l;
    search(root, p, l);
    return l;
  }
  bool search(TreeNode* root, TreeNode* p, vector<TreeNode*>& l) {
    if (!root) return false;
    if (root == p || search(root->left, p, l) || search(root->right, p, l)) {
      l.push_back(root);
      return true;
    }
    return false;
  }
};
// @lc code=end
