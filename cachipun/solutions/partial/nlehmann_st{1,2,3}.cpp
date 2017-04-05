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
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> color;

void dfs(int n, int c) {
  if (color[n] == -1)
    color[n] = c;
  else if (color[n] != c)
    throw false;
  for (auto pv : graph[n]) {
    int v = pv.first;
    int m = pv.second;
    switch (m) {
    case 0: dfs(v, (color[n] - 1 + 3)%3); break;
    case 1: dfs(v, color[n]); break;
    case 2: dfs(v, (color[n] + 1)%3); break;
    }
  }
}

int main() {
  int J, Q;
  cin >> J >> Q;

  graph.resize(J);

  int count = 0;
  for (int i = 0; i < Q; ++i) {
    int a, b, m;
    cin >> a >> b >> m;
    a--;
    b--;
    int m1, m2;
    switch (m) {
    case 0: m1 = 0; m2 = 2; break;
    case 1: m1 = m2 = 1; break;
    case 2: m1 = 2; m2 = 0; break;
    }
    graph[a].emplace_back(b, m1);
    graph[b].emplace_back(a, m2);

    bool consistent = true;
    try {
      color.clear();
      color.resize(J, -1);
      for (int i = 0; i < J; ++i)
        if (color[i] == -1)
          dfs(i, 0);
    } catch (bool) {
      consistent = false;
    }
    if (not consistent) {
      graph[a].pop_back();
      graph[b].pop_back();
      count++;
    }
  }
  cout << count << "\n";
}
