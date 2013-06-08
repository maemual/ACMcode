import java.util.*;
import java.math.BigDecimal;

public class Main {
	public static void main(String[] args) {
		BigDecimal x;
		int y;
		String ans;
		Scanner input = new Scanner(System.in);
		while (input.hasNextBigDecimal()){
			x = input.nextBigDecimal();
			y = input.nextInt();
			x = x.pow(y);
			ans = x.stripTrailingZeros().toPlainString();
			if (ans.startsWith("0."))
				ans = ans.substring(1);
			System.out.println(ans);			
		}
	}
}
