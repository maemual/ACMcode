import java.util.Scanner;

public class Main {
	static int numOfNode(int x) {
		for (int i = 1;; i++) {
			x -= inx[i];
			if (x <= 0)
				return x + inx[i];
		}
	}

	static void numOfL(int x, int[] LR) {
		int tmp = numOfNode(x);
		System.out.println(tmp);
		for (int i = 1; i < tmp; i++) {
			x -= inx[i];
		}
		for (int i = 0; i <= tmp - 1; i++) {
			x -= inx[i] * inx[tmp - i - 1];
			if (x <= 0) {
				x += inx[i] * inx[tmp - i - 1];
				LR[0] = LR[1] = x;
				for (int j = 1; j < i; j++) {
					LR[0] += inx[j];
				}
				for (int j = 1; j < tmp - i - 1; j++) {
					LR[1] += inx[j];
				}
				break;
			}
		}
	}

	static void dfs(int nodes, int th) {
		if (nodes == 1) {
			System.out.print("X");
			return;
		}
		int tmp = th;
		int i;
		for (i = 0; i < nodes; i++) {
			tmp -= inx[i] * inx[nodes - i - 1];
			if (tmp <= 0)
				break;
		}
		tmp += inx[i] * inx[nodes - i - 1];
		int x, y;
		x = ((tmp - 1) / inx[nodes - i - 1]) + 1;
		y = tmp - (x - 1) * inx[nodes - i - 1];
		if ((nodes - i - 1 > 0) && (i > 0)) {
			System.out.print("(");
			dfs(i, x);
			System.out.print(")X(");
			dfs(nodes - i - 1, y);
			System.out.print(")");
		} else if (i > 0) {
			System.out.print("(");
			dfs(i, x);
			System.out.print(")X");
		} else {
			System.out.print("X(");
			dfs(nodes - i - 1, y);
			System.out.print(")");
		}
	}

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int x = cin.nextInt();
			if (x == 0)
				break;
			int i;
			for (i = 1;; i++) {
				x -= inx[i];
				if (x <= 0)
					break;
			}
			x += inx[i];
			dfs(i, x);
			System.out.println();
		}
	}

	static final int[] inx = { 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796,
			58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790,
			477638700 };
}