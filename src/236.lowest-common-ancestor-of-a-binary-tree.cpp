#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start

class Solution {
  unordered_map<TreeNode*, TreeNode*> parent;

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    BFS(root, p, q);
    unordered_set<int> pp, qq;
    while (p || q) {
      if (p) {
        pp.insert(p->val);
        if (qq.find(p->val) != qq.end()) return p;
        p = parent[p];
      }
      if (q) {
        qq.insert(q->val);
        if (pp.find(q->val) != pp.end()) return q;
        q = parent[q];
      }
    }
    return nullptr;
  }
  void BFS(TreeNode* root, TreeNode* p, TreeNode* q) {
    queue<TreeNode*> qq;
    qq.push(root);
    while (!qq.empty()) {
      for (auto i : {qq.front()->left, qq.front()->right})
        if (i) {
          qq.push(i);
          parent[i] = qq.front();
          if (i == p) p = nullptr;
          if (i == q) q = nullptr;
        }
      qq.pop();
      if (!p && !q) break;
    }
  }
};
// @lc code=end

int main() {
  auto root = build_tree({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4});

  Solution s;
  s.lowestCommonAncestor(root, root->left, root->right);

  return 0;
}