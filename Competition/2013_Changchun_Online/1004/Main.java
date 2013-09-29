import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int T;
		T = cin.nextInt();
		int m, n;
		BigInteger N;
		BigInteger M;
		BigInteger ans;
		for (int k = 0; k < T; k++){
			m = cin.nextInt();
			n = cin.nextInt();
			N = new BigInteger(String.valueOf(n));
			M = new BigInteger(String.valueOf(m));
			M = M.pow(n - 1);
			ans = M.gcd(N);
			N = N.divide(ans);
			M = M.divide(ans);
			System.out.println(N + "/" + M);
		}
	}
}
