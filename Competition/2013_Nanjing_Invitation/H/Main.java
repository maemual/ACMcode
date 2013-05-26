import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		int[] arr = new int[MAX_LEN + 5];
		int x;
		while (cin.hasNext()){
			for (int i = 0; i < MAX_LEN + 5; i++)
				arr[i] = 0;
			int n = cin.nextInt();
			int ans = 0;
			for (int i = 0; i < n+1; i++){
				x = cin.nextInt();
				arr[x]++;
				if (arr[x] == 2){
					ans = x;
				}
			}
			System.out.println(ans);
		}
	}
	private static final int MAX_LEN = 1000;
}