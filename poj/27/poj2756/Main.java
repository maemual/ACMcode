import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		for (int i = 1; i <= n; i++)
		{
			if (cin.hasNextBigInteger() == false)
			  cin.skip("\\s\\D");
			BigInteger a = cin.nextBigInteger();
			if (cin.hasNextBigInteger() == false)
			  cin.skip("\\s\\D");
			BigInteger b = cin.nextBigInteger();
			System.out.println(a.add(b));
		}
	}
}
