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

int main() {
  int N = 151;
  vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N)));
  for(int x = 0; x < N; x++){
    for(int y = 0; y < N; y++){
      for(int z = 0; z < N; z++){
        dp[x][y][z] = N*N*N;
      }
    }
  }
  dp[0][0][0] = 0;
  for(int x = 0; x < N; x++){
    for(int y = 0; y < N; y++){
      for(int z = 0; z < N; z++){
        if(x > 0 || y > 0 || z > 0){
          int a = 2*x; int b = 2*y; int c = 2*z;
          while(a < N && b < N && c < N){
            if(dp[a][b][c] > dp[x][y][z]){
              dp[a][b][c] = dp[x][y][z];
            }
            a += x; b += y; c += z;
          }
        }
        if(x < N-1 && dp[x+1][y][z] > dp[x][y][z]+1){
          dp[x+1][y][z] = dp[x][y][z]+1;
        }
        if(y < N-1 && dp[x][y+1][z] > dp[x][y][z]+1){
          dp[x][y+1][z] = dp[x][y][z]+1;
        }
        if(z < N-1 && dp[x][y][z+1] > dp[x][y][z]+1){
          dp[x][y][z+1] = dp[x][y][z]+1;
        }
      }
    }
  }
  int a, b, c;
  cin >> a >> b >> c;
  cout << dp[a][b][c] << "\n";
}
