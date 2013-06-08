import java.math.*;
import java.util.*;

public class Main
{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		int n;
		String a,b;
		BigInteger ta,tb,tc;
		while (true)
		{
			n = cin.nextInt();
			if (n == 0)
			  break;
			a = cin.next();
			b = cin.next();
			ta = new BigInteger(a,n);
			tb = new BigInteger(b,n);
			tc = ta.mod(tb);
			System.out.println(tc.toString(n));
		}
	}
}
