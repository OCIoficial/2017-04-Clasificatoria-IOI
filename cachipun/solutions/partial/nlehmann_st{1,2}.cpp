/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

bool beats(int a, int b) {
  return (a - b + 3) % 3 == 1;
}

vector<vector<int>> info;
bool consistent() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        vector<int> world = {i, j, k};
        bool b = true;
        for (auto obs : info) {
          if (obs[2] == 1 and world[obs[0]] != world[obs[1]])
            b = false;
          if (obs[2] == 2 and not beats(world[obs[0]], world[obs[1]]))
            b = false;
        }
        if (b)
          return true;
      }
    }
  }
  return false;
}

int main() {
  int J, Q;
  cin >> J >> Q;

  int count = 0;
  for (int i = 0; i < Q; ++i) {
    int a, b, m;
    cin >> a >> b >> m;
    a--;
    b--;
    if (m == 0) {
      swap(a, b);
      m = 2;
    }
    info.push_back({a, b, m});
    if (not consistent()) {
      count++;
      info.pop_back();
    }
  }
  cout << count << "\n";
  return 0;
}

