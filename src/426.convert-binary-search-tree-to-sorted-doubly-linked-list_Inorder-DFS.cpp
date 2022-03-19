#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 */

// @lc code=start
class Solution {
  public:
  // the smallest (first) and the largest (last) nodes
  Node* first = NULL;
  Node* last = NULL;

  void helper(Node* node) {
    if (node) {
      // left
      helper(node->left);
      // node 
      if (last) {
        // link the previous node (last)
        // with the current one (node)
        last->right = node;
        node->left = last;
      }
      else {
        // keep the smallest node
        // to close DLL later on
        first = node;
      }
      last = node;
      // right
      helper(node->right);
    }
  }

  Node* treeToDoublyList(Node* root) {
    if (!root) return NULL;

    helper(root);
    // close DLL
    last->right = first;
    first->left = last;
    return first;
  }
};

// @lc code=end

int main() {
  Node* root = build_tree<Node>({4, 2, 5, 1, 3});
  Solution s;
  auto r = s.treeToDoublyList(root);
  return 0;
}
