#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
  vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};

    vector<int> rst;
    vector<TreeNode*> q1;
    q1.push_back(root);

    while (!q1.empty()) {
      rst.push_back(q1.back()->val);
      vector<TreeNode*> q2;
      for (auto i : q1) {
        if (i->left) q2.push_back(i->left);
        if (i->right) q2.push_back(i->right);
      }
      q1 = std::move(q2);
    }

    return rst;
  }
};
// @lc code=end
