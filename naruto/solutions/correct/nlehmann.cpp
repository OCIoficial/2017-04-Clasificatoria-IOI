/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int MAX;

template<typename Fun>
void neighbors(int a, int b, int c, Fun fun) {
  int k = 2;
  if (a != 0 or b != 0 or c != 0)
    while (k*a <= MAX and k*b <= MAX and k*c <= MAX) {
      fun(k*a, k*b, k*c, 0);
      k++;
    }
  if (a + 1 <= MAX)
    fun(a + 1, b, c, 1);
  if (b + 1 <= MAX)
    fun(a, b + 1, c, 1);
  if (c + 1 <= MAX)
    fun(a, b, c + 1, 1);
}

vector<vector<vector<int>>> dist;
void fill() {
  dist.resize(101);
  for (int i = 0; i < 101; ++i) {
    dist[i].resize(101);
    for (int j = 0; j < 101; ++j) {
      dist[i][j].resize(101, INT_MAX);
    }
  }
}


int dijkstra(int a, int b, int c) {
  int na, nb, nc, nd;
  priority_queue<tuple<int, int, int, int>> q;
  fill();
  q.emplace(0, 0, 0, 0);
  dist[0][0][0] = 0;
  while (not q.empty()) {
    tie(nd, na, nb, nc) = q.top();
    nd = -nd;
    q.pop();

    if (na == a and nb == b and nc == c)
      return nd;

    if(nd > dist[na][nb][nc])
      continue;

    neighbors(na, nb, nc, [&](int va, int vb, int vc, int vd) {
        int new_dist = vd + nd;
        if (new_dist < dist[va][vb][vc]) {
          q.emplace(-new_dist, va, vb, vc);
          dist[va][vb][vc] = new_dist;
        }
      });
  }
  return INT_MAX;
}



int main() {
  int a, b, c;

  cin >> a >> b >> c;
  MAX = max(a, max(b, c));

  cout << dijkstra(a, b, c) << "\n";
  return 0;
}
