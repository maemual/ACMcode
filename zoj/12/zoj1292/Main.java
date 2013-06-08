import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			int cas;
			cas = cin.nextInt();
			for(int i=0;i<cas;i++){
				if(i!=0) System.out.println();
				BigInteger a,b=BigInteger.valueOf(0);
				while(true){
					a=cin.nextBigInteger();
					if(a.compareTo(BigInteger.valueOf(0))==0) break;
					b=b.add(a);
				}
				System.out.println(b);
			}
		}
	}
}
