import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigDecimal a;
		System.out.println("Problem 4 by team x");
		while(cin.hasNextBigDecimal()){
			a = cin.nextBigDecimal();
			System.out.println();
			System.out.println(BigInteger.ONE+" / "+a+" =");
			System.out.println(BigDecimal.ONE.divide(a).toPlainString());
		}
		System.out.println("End of problem 4 by team x");
	}
}
