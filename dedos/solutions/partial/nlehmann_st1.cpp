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
  int T, D, C, b;
  cin >> T >> D >> C;

  int count = 0;
  for (int i = 0; i < T; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> b;
      if (b == 0) {
        count += 1;
        break;
      }
    }
  }
  cout << count << "\n";
  return 0;
}
