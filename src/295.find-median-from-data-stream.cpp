#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    if (h1.empty()) {
      h1.push(num);
      return;
    }
    if (num <= h1.top()) h1.push(num);
    else h2.push(num);
    if (h1.size() == h2.size() + 2) {
      h2.push(h1.top());
      h1.pop();
    }
    if (h2.size() == h1.size() + 2) {
      h1.push(h2.top());
      h2.pop();
    }
  }

  double findMedian() {
    if (h1.size() == h2.size()) return (h1.top() + h2.top()) / 2.0;
    return h1.size() > h2.size() ? h1.top() : h2.top();
  }

  priority_queue<int> h1;
  priority_queue<int, vector<int>, greater<>> h2;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
