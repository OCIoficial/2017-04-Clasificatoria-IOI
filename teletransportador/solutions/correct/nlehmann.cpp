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
vector<int> A, B;
int N;

long cost(int C) {
  long sum = 0;
  for (int i = 0; i < N; ++i)
    sum += abs(C - A[i])*B[i];
  return sum;
}

int main() {
  cin >> N;

  A.resize(N);
  B.resize(N);
  int l = INT_MAX, r = INT_MIN;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    l = min(A[i], l);
    r = max(A[i], r);
  }
  for (int i = 0; i < N; ++i)
    cin >> B[i];

  while (l < r) {
    int m = l + (r - l)/2;
    if (cost(m) <= cost(m+1))
      r = m;
    else
      l = m + 1;
  }
  cout << l << "\n";
  return 0;
}
