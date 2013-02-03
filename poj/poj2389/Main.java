import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		BigInteger a = new BigInteger(cin.next());
		BigInteger b = new BigInteger(cin.next());
		System.out.println(a.multiply(b));
	}
}
