import java.io.*;
import java.util.*;
public class Main {
  public static void main(String[] args){
	Scanner input = new Scanner(System.in);
	int cas = input.nextInt();
	int[] arr = new int[1005];
	for (int i = 1; i <= 1000; i++){
		int x = (int) Math.sqrt(i);
		if (x * x != i)
			continue;
		String s1 = new String(Integer.valueOf(i).toString());
		String s2 = new String();
		for (int j = s1.length()-1; j >= 0; j--)
			s2 += s1.charAt(j);
		if (s1.equalsIgnoreCase(s2) == false)
			continue;
		
		s1 = new String(Integer.valueOf(x).toString());
		s2 = new String();
		for (int j = s1.length()-1; j >= 0; j--)
			s2 += s1.charAt(j);
		if (s1.equals(s2) == false)
			continue;
		arr[i] = 1;
	}
	for (int k = 1; k <= cas; k++){
		int a = input.nextInt();
		int b = input.nextInt();
		int sum = 0;
		for (int i = a; i <= b; i++){
			if (arr[i] == 1)
				sum++;
		}
		System.out.printf("Case #%d: %d\n", k, sum);
	}
  }
}
