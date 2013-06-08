import java.util.ArrayList;
import java.util.Scanner;
import java.math.*;

public class Main{
	public static int dp(int x, int y){
		if (vis[x][y] > 0){
			return vis[x][y];
		}
		int max = 0;
		int cnt = 0;
		for (int i = 0; i < 4; i++){
			if (x + dx[i] >= 0 && x + dx[i] <= r-1
				&& y + dy[i] >= 0 && y + dy[i] <= c-1){
				if (map[x][y] < map[x+dx[i]][y+dy[i]]){
					cnt = dp(x+dx[i], y+dy[i]);
					if (max < cnt)
						max = cnt;
				}
			}
		}
		vis[x][y] = max + 1;
		return vis[x][y];
	}
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		r = cin.nextInt();
		c = cin.nextInt();
		map = new int[MAX_LEN+5][MAX_LEN+5];
		vis = new int[MAX_LEN+5][MAX_LEN+5];
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				map[i][j] = cin.nextInt();
				vis[i][j] = 0;
			}
		}
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				dp(i,j);
			}
		}
		int max = 0;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (max < vis[i][j])
					max = vis[i][j];
			}
		}
		System.out.println(max);
	}
	private final static int MAX_LEN = 100;
	private static int r;
	private static int c;
	private static int[][] vis;
	private static int[][] map;
	private final static int[] dx = {1,-1,0,0};
	private final static int[] dy = {0,0,1,-1};
}