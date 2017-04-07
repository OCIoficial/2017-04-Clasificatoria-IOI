import java.util.*;
import java.io.*;
public class mmunos {
	static final int N = 101;
	public static void main(String[] args) {
		int[][][] dp = new int[N][N][N];
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
		Scanner seer = new Scanner(System.in);
		int a = seer.nextInt();
		int b = seer.nextInt();
		int c = seer.nextInt();
		System.out.println(dp[a][b][c]);
	}
}
