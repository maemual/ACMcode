import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int cas = input.nextInt();
		BigInteger num;
		String str;
		int sum;
		while (cas-- != 0) {
			while (input.hasNextInt()) {
				int base = input.nextInt();
				if (base == 0)
					break;
				str = input.next();
				num = new BigInteger(str, base);
				sum = 0;
				for (int i = 0; i < str.length(); i++) {
					sum += str.charAt(i) - '0';
				}
				if (num.mod(new BigInteger(Integer.valueOf(sum).toString()))
						.compareTo(BigInteger.ZERO) == 0) {
					System.out.println("yes");
				} else {
					System.out.println("no");
				}
			}
			if (cas != 0)
				System.out.println();
		}
	}
}
