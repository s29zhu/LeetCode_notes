#include "stl_headers.hpp"
class NestedInteger {
 public:
  // Constructor initializes an empty nested list.
  NestedInteger();
  // Constructor initializes a single integer.
  NestedInteger(int value);
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;
  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;
  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to
  // it.
  void add(const NestedInteger& ni);
  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger>& getList() const;
};

/*
 * @lc app=leetcode id=339 lang=cpp
 *
 * [339] Nested List Weight Sum
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };<
 */
class Solution {
  int rst{0};

 public:
  int depthSum(vector<NestedInteger>& nestedList) {
    for (auto& i : nestedList) DFS(i, 1);
    return rst;
  }

  void DFS(const NestedInteger& n, int depth) {
    if (n.isInteger())
      rst += n.getInteger() * depth;
    else
      for (auto& i : n.getList()) DFS(i, depth + 1);
  }
};
// @lc code=end
