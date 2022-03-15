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
 * @lc app=leetcode id=314 lang=cpp
 *
 * [314] Binary Tree Vertical Order Traversal
 */

// @lc code=start

class Solution {
  unordered_map<TreeNode*, int> row, col;
  unordered_map<TreeNode*, TreeNode*> parent;
  vector<TreeNode*> nodes;
  void search_tree(TreeNode* n, TreeNode* p, int r, int c) {
    row[n] = r;
    col[n] = c;
    parent[n] = p;
    nodes.push_back(n);
    if (n->left) search_tree(n->left, n, r + 1, c - 1);
    if (n->right) search_tree(n->right, n, r + 1, c + 1);
  }

 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (!root) return {};
    search_tree(root, nullptr, 0, 0);
    function<bool(TreeNode*, TreeNode*)> comp = [&](TreeNode* n1,
                                                    TreeNode* n2) {
      return col[n1] != col[n2]   ? col[n1] < col[n2]
             : row[n1] != row[n2] ? row[n1] < row[n2]
                                  : comp(parent[n1], parent[n2]);
    };
    sort(nodes.begin(), nodes.end(), comp);
    vector<vector<int>> rst{{nodes.front()->val}};
    int c = col[nodes.front()];
    for (int i = 1; i < nodes.size(); ++i)
      if (col[nodes[i]] != c) {
        rst.push_back({nodes[i]->val});
        c = col[nodes[i]];
      } else {
        rst.back().push_back(nodes[i]->val);
      }
    return rst;
  }
};
// @lc code=end

int main() {
  Solution s;
  // [1, 2, 3, null, 4, 5, null, 6, null, 7, null, null, 8, 9, null, 10, null, null, 11]

  return 0;
}