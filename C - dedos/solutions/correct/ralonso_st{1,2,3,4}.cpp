#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int pow(int, int);

int max_anterior(vector<int> &estados, vector<int> &dedos);

int B = 5, C, D;

int main() {
  int T, b;
  bool repetido;

  cin >> T >> D >> C;

  int n_estados = pow(B + C, D);

  vector<int> dedos(D);
  vector<int> notas(B);
  vector<vector<int> > dp(2, vector<int>(n_estados, 0));

  for (int i = 1; i <= T; ++i) {
    for (int b = 0; b < B; ++b) {
      cin >> notas[b];
    }

    for (int estado = 0; estado < n_estados; ++estado) {
      // Info del estado
      int aux = estado;
      for (int d = 0; d < D; ++d) {
        dedos[d] = aux % (B + C);
        aux /= B + C;
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
        dp[i&1][estado] = max_anterior(dp[1-i&1], dedos);

        // Sumar puntaje de este tiempo
        for (int b = 0; b < B; ++b) {
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


int max_rec(vector<int> &ptje, vector<int> &act, vector<int> &ant);

int recursion(vector<int> &ptje, vector<int> &act, vector<int> &ant, int sel) {
  ant.push_back(sel);
  int m = max_rec(ptje, act, ant);
  ant.pop_back();
  return m;
}

int max_rec(vector<int> &ptje, vector<int> &act, vector<int> &ant) {
  int m = 0;
  if (ant.size() == D) {
    vector<int> candidato = ant;
    sort(candidato.begin(), candidato.end(), greater<int>());
    sort(ant.begin(), ant.end(), greater<int>());
    int estado = 0;
    int pot = 1;
    for (int i = 0; i < D; ++i) {
      estado += ant[i] * pot;
      pot *= B + C;
    }
    return ptje[estado];
  }
  else {
    if (act[ant.size()] == B || C == 0) {
      for (int i = 0; i < B; ++i) {
        m = max(m, recursion(ptje, act, ant, i));
      }
    }
    else if (act[ant.size()] < B) {
      m = max(m, recursion(ptje, act, ant, act[ant.size()]));
      m = max(m, recursion(ptje, act, ant, B + C - 1));
    }
    else {
      m = max(m, recursion(ptje, act, ant, act[ant.size()] - 1));
    }
  }
  return m;
}

int max_anterior(vector<int> &puntaje, vector<int> &act) {
  vector<int> ant;
  return max_rec(puntaje, act, ant);
}

int pow(int b, int x) {
  if (x == 0) return 1;
  if (x&1 == 0) return pow(b * b, x >> 1);
  return b * pow(b * b, x >> 1);
}
