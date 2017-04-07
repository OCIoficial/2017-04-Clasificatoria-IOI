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
#include <climits>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  for (int i = 0; i < N; ++i)
    cin >> B[i];

  int min = INT_MAX;
  int imin = 1;
  for (int C = 1; C <= 10; ++C) {
    int cost = 0;
    for (int i = 0; i < N; ++i)
      cost += abs(A[i]-C)*B[i];
    if (cost < min) {
      min = cost;
      imin = C;
    }
  }
  cout << imin << "\n";

  return 0;
}
