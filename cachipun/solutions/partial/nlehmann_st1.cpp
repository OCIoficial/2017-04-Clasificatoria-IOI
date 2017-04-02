/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

int main() {
  int J, Q;

  cin >> J >> Q;

  int M = -1;
  int count = 0;
  for (int i = 0; i < Q; ++i) {
    int a, b, m;
    cin >> a >> b >> m;
    if (a == 2 && b == 1) {
      if (m == 0)
        m = 2;
      else if (m == 2)
        m = 0;
    }
    if (M == -1)
      M = m;
    else if (M != m)
      count++;
  }
  cout << count << "\n";

  return 0;
}
