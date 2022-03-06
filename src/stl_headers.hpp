#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
void print_matrix(const vector<vector<T>>& mat) {
  for (size_t i = 0; i < mat.size(); ++i) {
    for (size_t j = 0; j < mat[0].size(); ++j) cout << mat[i][j] << "\t";
    cout << endl;
  }
}