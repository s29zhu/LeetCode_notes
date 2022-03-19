#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 */

// @lc code=start
class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    if (!root) return nullptr;
    convert(root);
    Node *l = leftmost(root), *r = rightmost(root);
    l->left = r;
    r->right = l;
    return l;
  }

  void convert(Node* root) {
    root->left = convert_left(root->left);
    root->right = convert_right(root->right);
    if (root->left) root->left->right = root;
    if (root->right) root->right->left = root;
  }

  Node* leftmost(Node* root) {
    Node* l = root;
    while (l->left) l = l->left;
    return l;
  }
  Node* rightmost(Node* root) {
    Node* r = root;
    while (r->right) r = r->right;
    return r;
  }

  Node* convert_left(Node* root) {
    if (!root) return nullptr;
    convert(root);
    return rightmost(root);
  }
  Node* convert_right(Node* root) {
    if (!root) return nullptr;
    convert(root);
    return leftmost(root);
  }
};
// @lc code=end

int main() {
  Node* root = build_tree<Node>({4, 2, 5, 1, 3});
  Solution s;
  auto r = s.treeToDoublyList(root);
  return 0;
}
