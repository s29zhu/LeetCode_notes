#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start

class Solution {
  struct Node {
    char c{'.'};
    int word_ID{-1}, depth{-1};
    vector<int> candidates;
    unordered_map<char, Node*> s;
    Node() {}
    Node(char c) : c(c) {}
    ~Node() {
      for (auto& i : s) delete i.second;
    }
    Node* find(char c) { return s.find(c) == s.end() ? nullptr : s[c]; }
  };
  struct Dictionary {
    Node* root;
    Dictionary(const vector<string>& words) {
      root = new Node();
      for (int i = 0; i < words.size(); ++i) add_word(words[i], i);
    }
    ~Dictionary() { delete root; }
    void add_word(const string& word, int ID) {
      Node* r = root;
      r->candidates.push_back(ID);
      int i = 0;
      while (i < word.size()) {
        Node* n = r->find(word[i]);
        if (!n) break;
        if (i < word.size() - 1) n->candidates.push_back(ID);
        r = n;
        ++i;
      }
      if (i != word.size())
        add_new_word(r, word, ID, i);
      else
        r->word_ID = ID;
    }
    void add_new_word(Node* root, const string& word, int ID, int start) {
      Node* r = root;
      for (int i = start; i < word.size(); ++i) {
        Node* n = new Node(word[i]);
        n->depth = r->depth + 1;
        if (i < word.size() - 1) n->candidates.push_back(ID);
        r->s[word[i]] = n;
        r = n;
      }
      r->word_ID = ID;
    }
  };
  bool is_palindrom(const string& word, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j)
      if (word[i] != word[j]) return false;
    return true;
  }

  void find_pair(const vector<string>& words, int ID, const Dictionary& dict,
                 vector<vector<int>>& rst) {
    Node* r = dict.root;
    if (r->word_ID != -1 && r->word_ID != ID &&
        is_palindrom(words[ID], 0, words[ID].size() - 1))
      rst.push_back({r->word_ID, ID});
    for (int i = words[ID].size() - 1; i >= 0; --i) {
      r = r->find(words[ID][i]);
      if (!r) return;
      if (r->word_ID != -1 && r->word_ID != ID &&
          is_palindrom(words[ID], 0, i - 1))
        rst.push_back({r->word_ID, ID});
    }
    for (auto& i : r->candidates)
      if (i != ID && is_palindrom(words[i], r->depth + 1, words[i].size() - 1))
        rst.push_back({i, ID});
  }

 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    Dictionary dict(words);
    vector<vector<int>> rst;
    for (int i = 0; i < words.size(); ++i) find_pair(words, i, dict, rst);
    return rst;
  }
};

// @lc code=end

int main() {
  vector<string> words{"bat", "tab", "cat", "aba", ""};
  Solution s;
  auto r = s.palindromePairs(words);
  return 0;
}