/*************************************************************************
	> File Name: Main.java
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月03日 星期日 10时00分47秒
 ************************************************************************/

import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		BigInteger base = BigInteger.valueOf(26);
		while (true){
			String str = in.next();
			if (str.charAt(0) == '*')
				break;
			String res1,res2;
			if (str.charAt(0) >= '0' && str.charAt(0) <= '9'){
				res2 = str;
				BigInteger ans = new BigInteger(str);
				BigInteger sum = new BigInteger(str);
				BigInteger tmp = BigInteger.ONE;
				BigInteger res[] = new BigInteger[220];
				int ns = 0;
				while (true){
					if (sum.equals(BigInteger.ZERO))
						break;
					res[ns++] = sum.mod(base);
					sum = sum.divide(base);
				}
				for (int i = ns-1; i >= 0; i--){
					System.out.print((char)(Integer.parseInt(res[i].toString(),10) + 'a' - 1));
				}
				for (int i = 0; i < 22 - ns; i++)
					System.out.print(' ');
				System.out.println(String.format("%,d", ans));
			}else{
				res1 = str;
				BigInteger sum = BigInteger.ZERO;
				BigInteger tmp = BigInteger.ONE;
				for (int i = 0; i < str.length(); i++){
					tmp = BigInteger.valueOf(str.charAt(i) - 'a' + 1);
					sum = sum.multiply(base);
					sum = sum.add(tmp);
				}
				System.out.print(res1);
				for (int i = 0; i < 22 - res1.length(); i++)
					System.out.print(' ');
				res2 = String.format("%,d", sum);
				System.out.println(res2);
			}
		}
	}
}

