/**
 * TLE
 */
import java.util.Scanner;

public class Main {
	static boolean check() {
		boolean[] c = new boolean[MAX_L];
		int[] st = new int[MAX_L];
		c[n - 1] = true;
		for (int k = n - 1; k >= 1; k--) {
			if (c[k] == false)
				continue;
			int p = st[k];
			for (int i = 0; i < l[k]; i++) {
				if (s[k][i] == -1) {
					p++;
				} else {
					if (c[s[k][i]]){
						for (int j = 0; j < len[s[k][i]]; j++){
							if (str.charAt(p + j) != str.charAt(st[s[k][i]] + j))
								return false;
						}
					}else{
						c[s[k][i]] = true;
						st[s[k][i]] = p;
					}
					p += len[s[k][i]];
				}
			}
		}
		return true;
	}

	static boolean dfs2(int i, int k, int mmax_len) {
		if (i == l[k]) {
			len[k] = 0;
			for (int j = 0; j < l[k]; j++) {
				len[k] += s[k][j] == -1 ? 1 : len[s[k][j]];
			}
			return dfs1(k + 1, Math.max(mmax_len, len[k]));
		} else {
			for (s[k][i] = k - 1; s[k][i] >= -1; s[k][i]--) {
				if (dfs2(i + 1, k, mmax_len))
					return true;
			}
		}
		return false;
	}

	static boolean dfs1(int k, int mmax_len) {
		int t = mmax_len;
		for (int i = k; i < n; i++)
			t *= limit[k];
		if (t < length)
			return false;

		if (k == n) {
			return len[k - 1] == length && check();
		} else {
			for (l[k] = limit[k]; l[k] >= 0; l[k]--) {
				if (dfs2(0, k, mmax_len))
					return true;
			}
		}
		return false;
	}

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		limit = new int[MAX_L];
		len = new int[MAX_L];
		l = new int[MAX_L];
		str = new String();
		s = new int[N][MAX_L];
		while (cin.hasNext()) {
			n = cin.nextInt();
			for (int i = n - 1; i >= 0; i--) {
				limit[i] = cin.nextInt();
			}
			str = cin.next();
			length = str.length();
			if (length > 256) {
				System.out.println("No");
				continue;
			}
			str = new StringBuilder(str).reverse().toString();
			if (dfs1(0, 1)) {
				System.out.println("Yes");
			} else {
				System.out.println("No");
			}
		}
	}

	static final int N = 4;
	static final int MAX_LEN = 500;
	static final int MAX_L = 4;
	static int n;
	static int length;
	static int[] limit;
	static int[] len;
	static int[] l;
	static int[][] s;
	static String str;
}
