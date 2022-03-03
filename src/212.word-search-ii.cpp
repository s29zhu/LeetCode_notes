#include "stl_headers.hpp"
/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
  class Node;
  class Dictionary;
  using Position = array<int, 2>;

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> found;
    auto dict = new Dictionary(words);
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[0].size(); ++j)
        search(board, {i, j}, dict, found);
    delete dict;
    return found;
  }

  void search(vector<vector<char>>& board, const Position& position,
              Dictionary* dict, vector<string>& found) {
    vector<Position> ps;
    stack<Node*> ns;
    Position lp{board.size() - 1, board[0].size() - 1};

    ns.push(dict->next_node(dict->root, position, board));
    if (!ns.top()) return;
    ps.push_back(position);

    while (!ns.empty()) {
      Node* n = ns.top();
      Position p = ps.back();
      ns.pop();
      ps.pop_back();
      if (!n->word.empty()) found.push_back(n->word);

      for (auto& np : neighbours(p, lp))
        if (dict->next_node(n, p, board) &&
            find(ps.begin(), ps.end(), np) != ps.end()) {
          ns.push(dict->next_node(n, p, board));
          ps.push_back(np);
        }
    }
  }

  vector<Position> neighbours(const Position& p, const Position& lp) {
    vector<Position> rst;
    for (int i = 0; i < 2; ++i) {
      if (p[i] > 0) {
        rst.push_back(p);
        rst.back()[i] - 1;
      }
      if (p[i] < lp[i]) {
        rst.push_back(p);
        rst.back()[i] + 1;
      }
    }
    return rst;
  }

 private:
  struct Node {
    char letter{'*'};
    string word;
    Node* parent{nullptr};
    unordered_map<char, Node*> children;

    Node() = default;
    Node(char c, Node* parent) : letter(c), parent(parent) {}
    ~Node() {
      for (auto& i : children) delete i.second;
    }

    Node* find(char c) {
      return children.find(c) == children.end() ? nullptr : children[c];
    }
  };
  struct Dictionary {
    Node* root{nullptr};
    Dictionary(const vector<string>& words) {
      root = new Node();
      for (auto& i : words) add_word(i);
    }
    ~Dictionary() { delete root; }

    void add_word(const string& word) {
      Node* node = root;
      for (int i = 0; i < word.size(); ++i) {
        Node* next = node->find(word[i]);
        if (next) {
          node = next;
        } else {
          build_link_list(word, i, node);
          break;
        }
      }
    }

    static void build_link_list(const string& word, int start, Node* root) {
      Node* node = root;
      for (int i = start; i < word.size(); ++i) {
        auto n = new Node(word[i], node);
        node->children[word[i]] = n;
        node = n;
      }
      node->word = word;
    }

    Node* next_node(Node* current_node, const Position& p,
                    vector<vector<char>>& board) {
      return current_node->find(board[p[0]][p[1]]);
    }
  };
};

;