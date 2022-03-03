#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start

class Solution {
  using Graph =
      unordered_map<string, priority_queue<string, vector<string>, greater<>>>;

 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    Graph dest;
    for (auto& i : tickets) dest[i[0]].push(i[1]);

    size_t N = tickets.size() + 1;

    stack<string> s, r;
    s.push("JFK");

    while (s.size() + r.size() < N) {
      while (dest[s.top()].empty()) {
        r.push(s.top());
        s.pop();
      }
      while (!dest[s.top()].empty()) {
        auto d = dest[s.top()].top();
        dest[s.top()].pop();
        s.push(d);
      }
    }

    vector<string> rst(N);
    for (int i = s.size() - 1; i >= 0; --i) {
      rst[i] = s.top();
      s.pop();
    }
    for (int i = N - r.size(); i < N; ++i) {
      rst[i] = r.top();
      r.pop();
    }
    return rst;
  }
};
// @lc code=end
/* class Solution {
  using Graph =
      unordered_map<string, priority_queue<string, vector<string>, greater<>>>;

 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    Graph dest;
    for (auto& i : tickets) dest[i[0]].push(i[1]);

    size_t N = tickets.size() + 1;

    stack<string> s, r;
    s.push("JFK");

    while (s.size() + r.size() < N) {
      while (dest[s.top()].empty()) {
        r.push(s.top());
        s.pop();
      }
      while (!dest[s.top()].empty()) {
        auto d = dest[s.top()].top();
        dest[s.top()].pop();
        s.push(d);
      }
    }

    vector<string> rst(N);
    for (int i = s.size() - 1; i >= 0; --i) {
      rst[i] = s.top();
      s.pop();
    }
    for (int i = N - r.size(); i < N; ++i) {
      rst[i] = r.top();
      r.pop();
    }
    return rst;
  }
}; */
