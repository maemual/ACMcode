import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		//System.out.println("Hello World!");
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()){
			int a = cin.nextInt();
			int b = cin.nextInt();
			System.out.println(a+b);
		}
	}
}
