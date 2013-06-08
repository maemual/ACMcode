import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger big = new BigInteger("10").pow(100);
		BigInteger biga,bigb,bigc;
		ArrayList<BigInteger> arr = new ArrayList<BigInteger>();
		arr.clear();
		biga = new BigInteger("1");
		bigb = new BigInteger("2");
		bigc = biga.add(bigb);
		arr.add(biga);
		arr.add(bigb);
		while (bigc.compareTo(big) < 0){
			bigc = biga.add(bigb);
			arr.add(bigc);
			biga = bigb;
			bigb = bigc;
		}
		//System.out.println(arr.size());
		while (cin.hasNextBigInteger()){
			biga = cin.nextBigInteger();
			bigb = cin.nextBigInteger();
			if (biga.equals(BigInteger.ZERO)==true && bigb.equals(BigInteger.ZERO)==true){
				break;
			}
			int i,j;
			for (i = 0; i < arr.size(); i++){
				if (arr.get(i).compareTo(biga) >= 0){
					//System.out.println(arr.get(i));
					break;
				}
			}
			for (j = i; j < arr.size(); j++){
				if (arr.get(j).compareTo(bigb) > 0){
					//System.out.println(arr.get(j));
					break;
				}
			}
			System.out.println(j-i);
		}
	}
}
