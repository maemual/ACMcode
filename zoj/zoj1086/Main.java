/*************************************************************************
	> File Name: Main.java
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月03日 星期日 12时01分37秒
 ************************************************************************/

import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			String p = cin.next(), pp, ppp;
			BigDecimal r = new BigDecimal(p);
			BigInteger g, gg;
			int len = p.length();
			// System.out.println(len);
			BigDecimal s = BigDecimal.valueOf(10.0).pow(len - 2);
			BigDecimal sss = BigDecimal.valueOf(8.0).pow(len - 2), ss;
			s = s.multiply(r);
			g = s.toBigInteger();
			pp = g.toString();
			gg = new BigInteger(pp, 8);
			ppp = gg.toString();
			ss = new BigDecimal(ppp);
			System.out.print(p + " [8] = ");
			System.out.print(ss.divide(sss));
			System.out.println(" [10]");
		}
	}
}
