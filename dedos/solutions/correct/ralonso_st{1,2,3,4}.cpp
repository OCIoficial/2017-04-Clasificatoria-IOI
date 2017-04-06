#include <iostream>
#include <vector>
#include <algorithm>

#define BOTONES 5

using namespace std;


int pow(int, int);

int max_anterior(vector<int> &estados, vector<int> &dedos, int B, int C, int D);

int main() {
  int T, D, C, b;
  bool repetido;

  cin >> T >> D >> C;

  int n_estados = pow(BOTONES + C, D);

  vector<int> dedos(D);
  vector<int> notas(BOTONES);
  vector<vector<int> > dp(2, vector<int>(n_estados, 0));

  for (int i = 1; i <= T; ++i) {
    for (int b = 0; b < BOTONES; ++b) {
      cin >> notas[b];
    }

    for (int estado = 0; estado < n_estados; ++estado) {
      // Info del estado
      int aux = estado;
      for (int d = 0; d < D; ++d) {
        dedos[d] = aux % (BOTONES + C);
        aux /= BOTONES + C;
      }
      repetido = false;
      for (int d = 1; d < D; ++d) {
        if (dedos[d] > dedos[d - 1]) {
          repetido = true;
          break;
        }
      }

      if (!repetido) {
        // Tomar el mejor estado anterior alcanzable
        dp[i&1][estado] = max_anterior(dp[1-i&1], dedos, BOTONES, C, D);

        // Sumar puntaje de este tiempo
        for (int b = 0; b < BOTONES; ++b) {
          if (notas[b]) {
            for (int d = 0; d < D; ++d) {
              if (dedos[d] == b) {
                dp[i&1][estado]++;
                break;
              }
            }
          }
        }
      }
    }
  }

  // Responder el mejor
  int m = 0;
  for (int estado = 0; estado < n_estados; ++estado) {
    if (m < dp[T&1][estado]) {
      m = dp[T&1][estado];
    }
  }
  cout << m << endl;
  return 0;
}

int max_rec(vector<int> &ptje, vector<int> &dedos, vector<int> stack, int B, int C, int D) {
  int m = 0;
  if (stack.size() == D) {
    sort(stack.begin(), stack.end(), greater<int>());
    int estado = 0;
    int pot = 1;
    for (int i = 0; i < D; ++i) {
      estado += stack[i] * pot;
      pot *= B + C;
    }
    return ptje[estado];
  }
  else {
    if (dedos[stack.size()] == B || C == 0) {
      for (int i = 0; i < B; ++i) {
        stack.push_back(i);
        m = max(m, max_rec(ptje, dedos, stack, B, C, D));
        stack.pop_back();
      }
    }
    else if (dedos[stack.size()] < B) {
      stack.push_back(dedos[stack.size()]);
      m = max(m, max_rec(ptje, dedos, stack, B, C, D));
      stack.pop_back();
      stack.push_back(B + C - 1);
      m = max(m, max_rec(ptje, dedos, stack, B, C, D));
      stack.pop_back();
    }
    else {
      stack.push_back(dedos[stack.size()]-1);
      m = max_rec(ptje, dedos, stack, B, C, D);
      stack.pop_back();
    }
  }
  return m;
}

int max_anterior(vector<int> &puntaje, vector<int> &dedos, int B, int C, int D) {
  return max_rec(puntaje, dedos, vector<int>(), B, C, D);
}

int pow(int b, int x) {
  if (x == 0) return 1;
  if (x&1 == 0) return pow(b*b, x>>1);
  return b * pow(b*b, x>>1);
}
